#include <Arduino.h>
#include <Stepper.h>
/*
learning to use stepper motor.
A stepper motor needs a separate Power Source.  HW131 is what we will use here.
We will use a driver as well for the Stepper motor. (see pics)
to build the circuit. 

*/
int stepsPerRevolution=2048; // 2048 steps make up a revolution.i.e. 360 degree
// order is in1, 3, 2 and 4 (these are from the motor driver)
// in1 - 8, in2 -9, in3-10, in4- 11
Stepper myStepper(stepsPerRevolution,8,10,9,11);
int motSpeed=20; //rpm 2 to 20 tested.
int dt=500;

void setup() {
Serial.begin(9600);
myStepper.setSpeed(motSpeed);
}

void loop() {
myStepper.step(stepsPerRevolution); // go full 360 degree, give stepsPerRevolution*2 for 2 rounds etc
delay(dt);
myStepper.step(-stepsPerRevolution); // go full 360 degree in opposite direction now.
delay(dt);
}

