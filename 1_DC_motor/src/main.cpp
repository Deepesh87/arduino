#include <Arduino.h>

/*
TESTING DC motor on arduino..
connect motors in any of the motor terminals in the Shield.(i did to M1)
NOTE: If powering the shield separately (a MUST ) make sure to use the jumper cautiously.
pls study the images attached
*/
// define pins
int motor_speed= 10; // INA to control speed of M1, must be PWM
int motor_polarity1= 9;
int motor_polarity2= 8;


void setup() {
pinMode(motor_speed,OUTPUT);
pinMode(motor_polarity1,OUTPUT);
pinMode(motor_polarity2,OUTPUT);
}

void loop() {
//set the speeed
analogWrite(motor_speed, 200); // range 0 -255
//run in one direction for 5 sec
digitalWrite(motor_polarity1, HIGH);
digitalWrite(motor_polarity2, LOW);
delay(5000);
//now stop for 10 sec
digitalWrite(motor_polarity1, LOW);
digitalWrite(motor_polarity2, LOW);
delay(10000);
// now run in reverse direction for 5sec
digitalWrite(motor_polarity1, LOW);
digitalWrite(motor_polarity2, HIGH);
delay(5000);
}
