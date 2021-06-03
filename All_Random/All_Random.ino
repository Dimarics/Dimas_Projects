void setup() {
  pinMode (6, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  String str = Serial.readString();
  if (str == "HIGH")
  digitalWrite (6, HIGH);
  digitalWrite (8, HIGH);
  digitalWrite (9, HIGH);
  digitalWrite (10, HIGH);
  if (str == "LOW")
  digitalWrite (6, LOW);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  digitalWrite (10, LOW);
  delay (10);
}
