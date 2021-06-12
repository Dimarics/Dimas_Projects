#include <iarduino_RF433_Transmitter.h>
#include <iarduino_RF433_Receiver.h>

iarduino_RF433_Transmitter radioTX(4);
iarduino_RF433_Receiver    radioRX(3);
int power;
int screen;
byte pipe;             

void setup(){
  Serial.begin(9600);
  radioTX.begin(1000);
  radioTX.openWritingPipe(5);
  radioRX.begin(1000);
  radioRX.openReadingPipe (5);
  radioRX.startListening ();
  pinMode (A5, INPUT);
}

void loop(){
  power = analogRead(A5);
  if(radioRX.available(&pipe)) {
    radioRX.read(&screen, sizeof(screen));
    Serial.println(screen);
  }
  radioTX.write(&power, sizeof(power));
  delay(200);
}
