#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableReceive(0);
  pinMode (13, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue();
    if (value == B1000)
      digitalWrite (13, HIGH);
    else if (value == B0100)
      digitalWrite (13, LOW);
    mySwitch.resetAvailable();
  }
}
