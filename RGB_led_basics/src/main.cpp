#include <Arduino.h>


const int PinR= 3;
const int PinG= 5;
const int PinB= 6;

void setup() {
pinMode(PinR, OUTPUT);
pinMode(PinG, OUTPUT);
pinMode(PinB, OUTPUT);
}

void loop() {
int red = 255;//random(0,255);
int green = 255;//random(0,255);
int blue = 255;//random(0,255);
// r light alone
analogWrite(PinR,red); 
delay(1000); 
// g alone
analogWrite(PinR,0); 
analogWrite(PinG,green);
delay(1000); 
// b alone
analogWrite(PinG,0); 
analogWrite(PinB,blue);
delay(1000);
// go for white light
analogWrite(PinR,red); 
analogWrite(PinG,green);
analogWrite(PinB,blue);
delay(1000);
// reset
analogWrite(PinR,0); 
analogWrite(PinG,0);
analogWrite(PinB,0);
delay(1000);
}
