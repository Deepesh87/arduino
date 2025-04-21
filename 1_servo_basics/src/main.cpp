#include <Arduino.h>
#include <Servo.h>

/*
connecting a servo
Red wire is the Power. connect to 5V,
Brown is the Ground
Orange is the control, connect to Pin 9 (in this example)
DONT PRESS ENTER. IT IS TAKEN AS 0

*/
int pos;
int ServoPin=9;
Servo myServo;

void setup()
{
  Serial.begin(9600);
  myServo.attach(ServoPin);
}

void loop()
{
Serial.print("what angle for the Servo? ");
while(Serial.available()==0){  
  //keep waiting until a value is given by user
}
pos= Serial.parseInt();
while (Serial.available() > 0) {
Serial.read();  // flush buffer otherwise it take the enter we press as \n and takes 0 as value
}
Serial.println(pos);
delay(1000);
myServo.write(pos);
}
