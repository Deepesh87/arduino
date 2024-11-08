#include <Arduino.h>
/*
red led glows if reading on photoresistor is <500 otherwise Green glows.
See circuit diagram in image.
photoresistr requires 5k Ohm resistor

*/
const int lightPin=A0; //read pin for photoresistor
const int redLight_pin=2;
const int greenLight_pin=7;
float lightValue=0;

void setup() {
  // put your setup code here, to run once:
pinMode(lightPin, INPUT);
pinMode(redLight_pin, OUTPUT);
pinMode(greenLight_pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
lightValue=analogRead(lightPin);
Serial.println(lightValue);
if (lightValue<500){
  digitalWrite(greenLight_pin,LOW); 
  digitalWrite(redLight_pin,HIGH);
}
else{
  digitalWrite(redLight_pin,LOW);
  digitalWrite(greenLight_pin,HIGH); 
}

delay(100);
}
