#include <Servo.h>

// === Motor pins ===
int M1A = 6;  
int M1B = 7;  
int M2A = 4;
int M2B = 5;

// === IR sensors ===
int IR_left = 2;     
int IR_right = 12;   

// === Ultrasonic pins ===
int trigPin = 11;
int echoPin = 8;

// === Servo motor ===
Servo servo;
int servoPin = 3;

// === Thresholds ===
int safeDistance = 20; // cm, obstacle detection distance

void setup() {
  // Motor pins
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  // IR sensors
  pinMode(IR_left, INPUT);
  pinMode(IR_right, INPUT);

  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo
  servo.attach(servoPin);
  servo.write(90); // center

  Serial.begin(9600);
}

void loop() {
  int leftIR = digitalRead(IR_left);
  int rightIR = digitalRead(IR_right);

  int distAhead = getDistance();

  Serial.print("Left IR: ");
  Serial.print(leftIR);
  Serial.print(" | Right IR: ");
  Serial.print(rightIR);
  Serial.print(" | Distance: ");
  Serial.println(distAhead);

  // --- Logic ---
  if (distAhead > safeDistance && leftIR == HIGH && rightIR == HIGH) {
    // Path clear and no cliff → move forward
    moveForward();
  }
  else {
    stopMotors();
    delay(200);

    // Scan left
    servo.write(150);
    delay(500);
    int distLeft = getDistance();

    // Scan right
    servo.write(30);
    delay(500);
    int distRight = getDistance();

    // Reset servo
    servo.write(90);
    delay(300);

    if (distLeft > distRight && distLeft > safeDistance) {
      // Turn left
      turnLeft();
      delay(400);
    }
    else if (distRight > distLeft && distRight > safeDistance) {
      // Turn right
      turnRight();
      delay(400);
    }
    else {
      // No way clear → reverse
      reverse();
      delay(600);
    }
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

void reverse() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void stopMotors() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
}

// === Ultrasonic Distance Function ===
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // cm
  return distance;
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
