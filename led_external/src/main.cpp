#include <Arduino.h>
/*
simple program. Connect LED to pin 13 witha  resistor of 330 ohm 
to the positive end and negative to ground
*/
 
 int ledPin=13;
 void setup(){
  pinMode(ledPin, OUTPUT);
 }

 void loop(){
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
 }