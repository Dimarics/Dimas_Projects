
const int SENCE = 14;

void setup() {
  Serial.begin (9600);
  pinMode (SENCE, INPUT);
}

void loop() {
  
  bool SenseState = digitalRead (SENCE);
  Serial.println (SenseState);
  delay (100);
}
