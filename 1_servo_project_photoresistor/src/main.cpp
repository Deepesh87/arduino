#include <Arduino.h>
#include <Servo.h>
/*
Turn servo 0 degree if photoresistor reads <450
otherwise turn 180
photoresistr requires 5k Ohm resistor.
Connect servo to separate power.

*/

int pos;
int ServoPin=9;
Servo myServo;
const int lightPin=A0; //read pin for photoresistor
float lightValue=0;

void setup()
{
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
  myServo.attach(ServoPin);
}

void loop()
{
lightValue=analogRead(lightPin);
Serial.println(lightValue);

if (lightValue<450){
pos= 0;
}
else{
pos= 180;
}
myServo.write(pos);
delay(1000);
}
