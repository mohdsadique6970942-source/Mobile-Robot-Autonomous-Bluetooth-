#define IR_LEFT  9   
#define IR_RIGHT 12   

#define ENA 11   
#define IN1 6    
#define IN2 5    

#define ENB 10    
#define IN3 3
#define IN4 4   

#define BASE_SPEED   65  
#define TURN_SPEED   55   
#define STOP_DELAY   200

#define ON_LINE  0
#define OFF_LINE 1

void setup() {
  pinMode(IR_LEFT,  INPUT);
  pinMode(IR_RIGHT, INPUT);
`
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);   
  stopMotors();
  delay(2000);          
}

void loop() {
  int leftSensor  = digitalRead(IR_LEFT);
  int rightSensor = digitalRead(IR_RIGHT);

  if (leftSensor == ON_LINE && rightSensor == ON_LINE) {

    moveForward(BASE_SPEED);

  } else if (leftSensor == ON_LINE && rightSensor == OFF_LINE) {
    turnLeft();

  } else if (leftSensor == OFF_LINE && rightSensor == ON_LINE) {
    turnRight();

  } else {
    stopMotors();
    
  }
}
void moveForward(int speed) {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed);
}

void turnLeft() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, BASE_SPEED);   

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);   
}

void turnRight() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);   

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, BASE_SPEED);  
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); 
}

void reverse() {
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, TURN_SPEED);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, TURN_SPEED);
}