// Motor pins
int M1A = 6;  
int M1B = 7;  
int M2A = 4;
int M2B = 5;

// IR sensors
int IR_left = 2;     // Left IR sensor
int IR_right = 12;   // Right IR sensor

void setup() {
  // Motor pins
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  // IR sensors
  pinMode(IR_left, INPUT);
  pinMode(IR_right, INPUT);

  Serial.begin(9600);
}

void loop() {
  int leftIR = digitalRead(IR_left);
  int rightIR = digitalRead(IR_right);

  Serial.print("Left IR: ");
  Serial.print(leftIR);
  Serial.print(" | Right IR: ");
  Serial.println(rightIR);

  // --- Avoidance Logic ---
  if (leftIR == LOW && rightIR == LOW) {      // Both clear
    moveForward();
  }
  else if (leftIR == HIGH && rightIR == LOW) {  // Obstacle on left
    turnRight();
    delay(400);  // small turn
  }
  else if (rightIR == HIGH && leftIR == LOW) {  // Obstacle on right
    turnLeft();
    delay(400);  // small turn
  }
  else if (leftIR == HIGH && rightIR == HIGH) {   // Both blocked
    reverse();
    delay(500);           // reverse for a while
    turnLeft();           // then turn (you can make random left/right if you want)
    delay(500);           // turning time
    moveForward();        // continue forward
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