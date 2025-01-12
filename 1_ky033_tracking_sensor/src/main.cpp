#include <Arduino.h>

/*
test the sensor. Led connected to pin 12, sensor to pin 4. Sensor outputs high by default, low when it detects an object.
*/
const int led=13;
const int tracker=4;

void setup(){
pinMode(led,OUTPUT);
pinMode(tracker, INPUT);
Serial.begin(9600);
}

void loop(){
int val= digitalRead(tracker);
Serial.println(val);
if(val==HIGH){
digitalWrite(led, HIGH);
}
else {
digitalWrite(led, LOW);
}
}