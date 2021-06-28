#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
RCSwitch mySwitch2 = RCSwitch();
int power;

void setup() {
  mySwitch.enableTransmit(4);
  mySwitch2.enableReceive(1);
  Serial.begin (9600);
  pinMode (A5, INPUT);
}

void loop() {
  power = analogRead(A5);
  int siz = sizeof(power);
  mySwitch.send (power, 16);
  delay (200);
  
  if (mySwitch2.available()) {
    Serial.println(mySwitch2.getReceivedValue());
    mySwitch.resetAvailable();
  }
}
