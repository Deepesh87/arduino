#include <Arduino.h>
#include <Stepper.h>

int stepsPerRevolution=2048;
Stepper myStepper(stepsPerRevolution,8,9,10,11);
int motSpeed=10; //rpm
int dt=500;

void setup() {
Serial.begin(9600);
myStepper.setSpeed(motSpeed);
}

void loop() {
myStepper.step(stepsPerRevolution);
delay(dt);
myStepper.step(-stepsPerRevolution);
delay(dt);
Serial.println("hello");
}

