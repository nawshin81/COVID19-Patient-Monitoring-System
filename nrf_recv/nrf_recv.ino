#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>



int msg[1];
RF24 radio(9,10);  //CE, CSN
const uint64_t pipe = 0xF0F0F0F0D2D;

void setup() {
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);

digitalWrite(3, HIGH);
delay(1000);
digitalWrite(3, LOW);
delay(500);
digitalWrite(3, HIGH);
delay(1000);
digitalWrite(3, LOW);
delay(500);
digitalWrite(4, HIGH);
delay(1000);
digitalWrite(4, LOW);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (radio.available()) {
    digitalWrite(4, HIGH);
    
    bool done = false;

    while (!done) {
      done = radio.read(msg, 1);
      Serial.println(msg[0]);
}
}

else
digitalWrite(4, LOW);
}
