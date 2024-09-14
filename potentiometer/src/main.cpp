#include <Arduino.h>

// use a potentiometer to vary the resistance and see the VOltages
// the the diagram of the set up
// learn about the functioning of a potentiometer
/*
plug middle of potentiometr to analog pin A0.
Plus the other pins to Ground and 5V
based on the code the Serial monitor/plot will print the voltage it reads on A0

*/

void setup() {
  Serial.begin(9600); // send serial data to the computer at 9600 bits per second
}

void loop() {
int sensorValue = analogRead(A0); // measure the voltage on pin A0
Serial.println(sensorValue);
delay(10);
}