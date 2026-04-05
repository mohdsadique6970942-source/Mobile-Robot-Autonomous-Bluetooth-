#include <SoftwareSerial.h>

// ===== Bluetooth =====
SoftwareSerial BT(10, 11); // RX, TX

// ===== Motor pins =====
int M1A = 6;  
int M1B = 7;  
int M2A = 4;
int M2B = 5;

char command;

void setup() {
  // Motor pins
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  BT.begin(9600);   // HC-05 baud rate
}

void loop() {

  if (BT.available()) {
    command = BT.read();

    if (command == 'F') moveForward();
    else if (command == 'B') reverse();
    else if (command == 'L') turnLeft();
    else if (command == 'R') turnRight();
    else if (command == 'S') stopMotors();
  }
}

// ===== Motor Functions =====
void moveForward() {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void reverse() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
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
}
