#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int msg[1];
RF24 radio(9,10);   //CE, CSN
const uint64_t pipe = 0xF0F0F0F0D2D;

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);

}

void loop() {
  // put your main code here, to run repeatedly:
  msg[0] = 112;
  radio.write(msg, 1);


}
