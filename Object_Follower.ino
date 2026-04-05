// === Object Detecting with 2 IR Sensors and 2 Motors ===

// Motor pins
int M1A = 6;  
int M1B = 7;  
int M2A = 4;
int M2B = 5;

// IR sensors
int IR_sensor1 = 12;   // Right sensor
int IR_sensor2 = 2;    // Left sensor

void setup() {
  // Motor pins
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  // IR sensors
  pinMode(IR_sensor1, INPUT);
  pinMode(IR_sensor2, INPUT);

  Serial.begin(9600);
}

void loop() {
  int irValue1 = digitalRead(IR_sensor1); // Right
  int irValue2 = digitalRead(IR_sensor2); // Left

  Serial.print("IR Sensor1: ");
  Serial.println(irValue1);
  Serial.print("IR Sensor2: ");
  Serial.println(irValue2);

  // --- Decision Making ---
  if (irValue1 == LOW && irValue2 == LOW) {       // Both detect
    moveForward();
  }
  else if (irValue1 == LOW && irValue2 == HIGH) { // Only right detects
    turnLeft();
  }
  else if (irValue1 == HIGH && irValue2 == LOW) { // Only left detects
    turnRight();
  }
  else {                                          // None detect
    stopMotors();
  }

  delay(100);
}

// === Motor Functions ===
void moveForward() {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void turnLeft() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void turnRight() {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void stopMotors() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
