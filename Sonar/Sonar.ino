#include <NewPing.h>

const unsigned int ECHO_PIN = 11;
const unsigned int TRIG_PIN = 10;

NewPing sonar (TRIG_PIN, ECHO_PIN, 200);

void setup() {
  Serial.begin (9600);
  pinMode (TRIG_PIN, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.println (distance);
  delay (100);
}
