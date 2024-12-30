#include <Arduino.h>
#include <AFMotor.h>

/*
do not install AFMotorv2 library
connect stepper motor to either m1 & 2 (port1)
or M2 & M3(port2)
NOTE: If powering the shield separately make sure to use the jumper cautiously.
*/

AF_Stepper my_stepmotor(200,1); //we connect to M1 on the shield
int motSpeed=10; //rpm

void setup() {
  my_stepmotor.setSpeed(motSpeed);
}

void loop() {
my_stepmotor.step(100, FORWARD, MICROSTEP);
// my_stepmotor.step(250, BACKWARD, MICROSTEP);
delay(1000);

}
