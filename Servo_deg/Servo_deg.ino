#include <Servo.h>
Servo Servo1;

int power;

void setup() {
  pinMode (A5, INPUT);
  Serial.begin (9600);
  Servo1. attach (A3);
}

void loop() {
  power = analogRead(A5)/6;
  Servo1.write (power);
  Serial.println (power);
}
