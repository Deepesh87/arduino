#include <Arduino.h>
#include <Servo.h>

/*
connecting a servo
Red wire is the Power. connect to 5V,
Brown is the Ground
Orange is the control, connect to Pin 9 (in this example)

*/
int pos = 0;
int ServoPin=9;
Servo myServo;

void setup()
{
  Serial.begin(9600);
  myServo.attach(ServoPin);
}

void loop()
{
myServo.write(pos);
Serial.println("what angle for the Servo?");
  while(Serial.available()==0){  
    //keep waiting until a value is given by user
  }
pos= Serial.parseInt();
delay(1000);
}