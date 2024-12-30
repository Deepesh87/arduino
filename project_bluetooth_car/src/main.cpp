#include <Arduino.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>

/*
use the motor shield, connect all 4 motors, you might have to change +/- to align motor direction of rotation
Power both motor shield and arduino with 9V battery (NOte: do remove the jack else it will BURN)
Connect bluetooth 4 wires to motor shield
TXD will connect to S,
RX will be to outermost and inner side.
use the app Arduino Bluetooth App on Android.
*/

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

// initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); // for my connection this is front RHS
AF_DCMotor motor2(2, MOTOR12_1KHZ); // for my connection this is rear RHS
AF_DCMotor motor3(3, MOTOR34_1KHZ); // for my connection this is rear LHS
AF_DCMotor motor4(4, MOTOR34_1KHZ); // for my connection this is front LHS

char command;

void setup()
{
  bluetoothSerial.begin(9600); // Set the baud rate to your Bluetooth module.
}

void loop()
{
  if (bluetoothSerial.available() > 0)
  {
    command = bluetoothSerial.read();
    Stop();
    // initialize with motors stoped

    switch (command)
    {
    case 'F':
      forward();
      break;
    case 'B':
      back();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    }
  }
}

void forward()
{
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD);  // rotate the motor clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(FORWARD);  // rotate the motor clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(FORWARD);  // rotate the motor clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(FORWARD);  // rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(BACKWARD); // rotate the motor anti-clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(BACKWARD); // rotate the motor anti-clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(BACKWARD); // rotate the motor anti-clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(BACKWARD); // rotate the motor anti-clockwise
}

void right()
{
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(BACKWARD); // rotate the motor anti-clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(BACKWARD); // rotate the motor anti-clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(FORWARD);  // rotate the motor clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(FORWARD);  // rotate the motor clockwise
}

void left()
{
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD);  // rotate the motor clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(FORWARD);  // rotate the motor clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(BACKWARD); // rotate the motor anti-clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(BACKWARD); // rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0);  // Define minimum velocity
  motor1.run(RELEASE); // stop the motor when release the button
  motor2.setSpeed(0);  // Define minimum velocity
  motor2.run(RELEASE); // rotate the motor clockwise
  motor3.setSpeed(0);  // Define minimum velocity
  motor3.run(RELEASE); // stop the motor when release the button
  motor4.setSpeed(0);  // Define minimum velocity
  motor4.run(RELEASE); // stop the motor when release the button
}