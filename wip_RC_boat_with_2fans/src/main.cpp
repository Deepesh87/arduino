#include <Arduino.h>
/*
DOnt connect tx, rx  of bluetooth while uploading code in Arduino
Rudder not needed, using the 2 fans will try to change direction.
It should go front and come back aswell?

https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/

NOTE: If powering the shield separately (a MUST ) make sure to use the jumper cautiously.
pls study the images attached
*/
// define pins
// int motor_speed_pin= 5; INA to control speed of M1, must be PWM. wont need will give it Full speed always.

int motor1_polarity1= 2;
int motor1_polarity2= 3;

char command;

void setup() {
pinMode(motor1_polarity1,OUTPUT);
pinMode(motor1_polarity2,OUTPUT);
Serial.begin(9600);
}

void loop() {

// run motor1===============
digitalWrite(motor1_polarity1, HIGH);
digitalWrite(motor1_polarity2, LOW);
// delay(5000);
// //stop motor 1
// digitalWrite(motor1_polarity1, LOW);
// digitalWrite(motor1_polarity2, LOW);

}

