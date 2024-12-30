#include <Arduino.h>

/*
Use a multimeter to check each output pin (2 to 13)
of arduino. Multimeter black or negative should connect to Negative/GND and 
positive or red should connect to each pin on eby one.
We should get 5V for each pin.
If we dont, that pin is damaged.
*/

const int pin2= 2;
const int pin3= 3;
const int pin4= 4;
const int pin5= 5;
const int pin6= 6;
const int pin7= 7;
const int pin8= 8;
const int pin9= 9;
const int pin10= 10;
const int pin11= 11;
const int pin12= 12;
const int pin13= 13;

void setup() {
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);
pinMode(pin7, OUTPUT);
pinMode(pin8, OUTPUT);
pinMode(pin9, OUTPUT);
pinMode(pin10, OUTPUT);
pinMode(pin11, OUTPUT);
pinMode(pin12, OUTPUT);
pinMode(pin13, OUTPUT);
}

void loop() {
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(pin4, HIGH);
digitalWrite(pin5, HIGH);
digitalWrite(pin6, HIGH);
digitalWrite(pin7, HIGH);
digitalWrite(pin8, HIGH);
digitalWrite(pin9, HIGH);
digitalWrite(pin10, HIGH);
digitalWrite(pin11, HIGH);
digitalWrite(pin12, HIGH);
digitalWrite(pin13, HIGH);
}

