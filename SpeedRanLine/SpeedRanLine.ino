int sum = 0;

const int RIGHT_SENCE = 14;
const int MIDDLE_SENCE = 15;
const int LEFT_SENCE = 16;

const int RightMotorSpeed = 90;
const int LeftMotorSpeed = 90;

const int RightMotorPin = 9;
const int RightMotorIn1 = 7;
const int RightMotorIn2 = 6;
const int LeftMotorPin = 3;
const int LeftMotorIn1 = 5;
const int LeftMotorIn2 = 4;

void setup() {
  Serial.begin (9600);
  pinMode (RIGHT_SENCE, INPUT);
  pinMode (MIDDLE_SENCE, INPUT);
  pinMode (LEFT_SENCE, INPUT);

  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  pinMode (RightMotorIn1, OUTPUT);
  pinMode (RightMotorIn2, OUTPUT);
  pinMode (LeftMotorIn1, OUTPUT);
  pinMode (LeftMotorIn2, OUTPUT);
}

void loop() {
  
  bool rightSenseState = !digitalRead (RIGHT_SENCE);
  bool middleSenseState = !digitalRead (MIDDLE_SENCE);
  bool leftSenseState = !digitalRead (LEFT_SENCE);
  Serial.print("Right sensor: ");
  Serial.print (rightSenseState);
  Serial.print(" Middle sensor: ");
  Serial.print (middleSenseState);
  Serial.print(" Left sensor: ");
  Serial.println (leftSenseState);

  if (leftSenseState == 1 && middleSenseState == 0 && rightSenseState == 0) { left (); sum = 0;} // - 100 влево
    
  else if (leftSenseState == 0 && middleSenseState == 0 && rightSenseState == 1) { right(); sum = 0;} // 001 - вправо
    
  else if (leftSenseState == 1 && middleSenseState == 1 && rightSenseState == 0) { right(); sum = 0;} // 110 - вправо
  
  else if (leftSenseState == 0 && middleSenseState == 1 && rightSenseState == 1) { left(); sum = 0;} // 011 - влево
  
  else if (leftSenseState == 1 && middleSenseState == 1 && rightSenseState == 1) { left(); sum = 0;} // 111 - влево
  
  else if (leftSenseState == 0 && middleSenseState == 0 && rightSenseState == 0) { // 000 - назад
    sum = sum + 1;
    if (leftSenseState == 0 && middleSenseState == 0 && rightSenseState == 0 && sum >= 10) {
      sum = 0;
      backward();
      delay (50);
    }
  } 

  else   { forward (); }
}

void forward () {
  digitalWrite (RightMotorIn1, LOW);
  digitalWrite (RightMotorIn2, HIGH);
  digitalWrite (LeftMotorIn1, LOW);
  digitalWrite (LeftMotorIn2, HIGH);
}

void backward () {
  digitalWrite (RightMotorIn1, HIGH);
  digitalWrite (RightMotorIn2, LOW);
  digitalWrite (LeftMotorIn1, HIGH);
  digitalWrite (LeftMotorIn2, LOW);
}

void left () {
  digitalWrite (RightMotorIn1, HIGH);
  digitalWrite (RightMotorIn2, LOW);
  digitalWrite (LeftMotorIn1, LOW);
  digitalWrite (LeftMotorIn2, HIGH);
}

void right () { 
  digitalWrite (RightMotorIn1, LOW);
  digitalWrite (RightMotorIn2, HIGH);
  digitalWrite (LeftMotorIn1, HIGH);
  digitalWrite (LeftMotorIn2, LOW);
}
