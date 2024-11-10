#include <Arduino.h>

/*
glow 4 leds indicating a binary counter.
e.g. first is 0, then 4th glows, then 3rd glows, then 3rd and 4th both, etc
for connection see image.

*/
const int pinA=2;
const int pinB=3;
const int pinC=4;
const int pinD=5;
int delaytime=600;
int pin_led_off(int x);
int pin_led_on(int x);

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
}

void loop() {
pin_led_off(pinA);
pin_led_off(pinB);
pin_led_off(pinC);
pin_led_off(pinD);
delay(delaytime);
// start=================
pin_led_on(pinA);
delay(delaytime);
pin_led_off(pinA);
delay(delaytime);
pin_led_on(pinB);
delay(delaytime);
pin_led_off(pinB);
delay(delaytime);
//==============
pin_led_on(pinA);
pin_led_on(pinB);
delay(delaytime);
//===
pin_led_off(pinA);
pin_led_off(pinB);
delay(delaytime);
//==========
pin_led_on(pinC);
delay(delaytime);
pin_led_off(pinC);
delay(delaytime);
//=======
pin_led_on(pinC);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinC);
pin_led_off(pinA);
delay(delaytime);
//=======
pin_led_on(pinC);
pin_led_on(pinB);
delay(delaytime);
//=======
pin_led_off(pinC);
pin_led_off(pinB);
delay(delaytime);
//========
pin_led_on(pinC);
pin_led_on(pinB);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinC);
pin_led_off(pinB);
pin_led_off(pinA);
delay(delaytime);
//========
pin_led_on(pinD);
delay(delaytime);
//=======
pin_led_off(pinD);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinA);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinB);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinB);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinB);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinB);
pin_led_off(pinA);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinC);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinC);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinC);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinC);
pin_led_off(pinA);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinC);
pin_led_on(pinB);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinC);
pin_led_off(pinB);
delay(delaytime);
//========
pin_led_on(pinD);
pin_led_on(pinC);
pin_led_on(pinB);
pin_led_on(pinA);
delay(delaytime);
//=======
pin_led_off(pinD);
pin_led_off(pinC);
pin_led_off(pinB);
pin_led_off(pinA);
delay(delaytime);
}

int pin_led_off(int x){
  digitalWrite(x, LOW);
}

int pin_led_on(int x){
  digitalWrite(x, HIGH);
}