#include <Arduino.h>
#include <AFMotor.h>

/*
do not install v2 library
connect motors in any of the motor terminals in the Shield.(i did to M1)
NOTE: If powering the shield separately make sure to use the jumper cautiously.
*/

AF_DCMotor motor(1); //we connect to M1 on the shield

void setup() {
}

void loop() {
motor.setSpeed(200);
motor.run(FORWARD);
delay(8000);
motor.run(RELEASE);
delay(8000);
motor.run(BACKWARD);
delay(8000);

}
