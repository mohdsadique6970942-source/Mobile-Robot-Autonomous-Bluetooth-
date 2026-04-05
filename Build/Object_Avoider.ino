#include <Wire.h>
#include <Adafruit_VL53L0X.h>

const int MPU = 0x68;  // MPU6050 I2C address
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// IMU variables
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float roll = 0, pitch = 0, yaw = 0;

unsigned long prevTime = 0;

// ---------------------- SETUP ----------------------
void setup() {
  Serial.begin(115200);

  // Start I2C on ESP32 custom pins
  Wire.begin(21, 22);
  delay(200);

  // Start MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);   // Power management register
  Wire.write(0);      // Wake up MPU6050
  Wire.endTransmission(true);

  Serial.println("MPU6050 initialized");

  // Start ToF Sensor
  if (!lox.begin()) {
    Serial.println("Failed to find VL53L0X sensor!");
    while (1);
  }
  Serial.println("VL53L0X initialized");

  prevTime = micros();
}

// ---------------------- READ MPU ----------------------
void readMPU() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;

  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
}

// ---------------------- LOOP ----------------------
void loop() {

  // dt calculation
  unsigned long now = micros();
  float dt = (now - prevTime) / 1000000.0;
  prevTime = now;

  readMPU();

  // Roll & Pitch from accelerometer
  float roll_acc = atan2(AccY, AccZ) * 180 / PI;
  float pitch_acc = atan(-AccX / sqrt(AccY * AccY + AccZ * AccZ)) * 180 / PI;

  // Complementary Filter
  roll = 0.98 * (roll + GyroX * dt) + 0.02 * roll_acc;
  pitch = 0.98 * (pitch + GyroY * dt) + 0.02 * pitch_acc;

  // Yaw (only from gyro)
  yaw += GyroZ * dt;

  // Read ToF distance
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  int distance = (measure.RangeStatus != 4) ? measure.RangeMilliMeter : -1;

  // --------- Print Data ----------
  Serial.print("Roll: ");  Serial.print(roll);
  Serial.print("   Pitch: "); Serial.print(pitch);
  Serial.print("   Yaw: ");   Serial.print(yaw);
  Serial.print("   Distance (mm): "); Serial.println(distance);

  delay(50);
}
