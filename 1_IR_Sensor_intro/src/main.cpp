#include <Arduino.h>

/*
begining to use IR sensor. range is around 5-7 cms. 
connect VCC, GND and out to 5V, GND and Pin 8 respectively.
*/

const int out_pin=8;
int pin_status;

void setup() {
  pinMode(out_pin, INPUT);
  Serial.begin(9600);
  Serial.println("This Sensor gives 1 when no object is detected and 0 when an object is detected");
}

void loop() {
pin_status = digitalRead(out_pin);
// got to know this through experimentation. ACTIVE LOW IR SENSOR
if (pin_status== HIGH){
Serial.println("No Object");
}
else{
  Serial.println("An object is detected");
}
delay(2000);
}

