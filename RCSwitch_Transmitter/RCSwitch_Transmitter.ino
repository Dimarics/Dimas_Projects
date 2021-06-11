#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(2);
}

void loop() {
  mySwitch.send (B0100);
  delay (1000);
  mySwitch.send (B1000);
  delay (1000);
}
