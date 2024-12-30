#include <Arduino.h>

// use a potentiometer to vary the resistance and dim the LED
// See the diagram of the set up
/*
plug middle of potentiometr to analog pin A0.
Plus the other pins to Ground and 5V
based on the code the Serial monitor/plot will print the voltage it reads on pin 9
see the photo of the setup
Connect the LED and its positive with a 330 Ohm resitor and with its output to pin 9 and ground 
*/

const int inputPin= A0;
const int outputPin= 9;
void setup() {
  Serial.begin(9600); // so we can see the plot as we tune the potentiometer
}

void loop() {
int sensorValue = analogRead(A0); // measure the voltage on pin A0
int outputValue= map(sensorValue, 0, 1023, 0, 255);// linearly tone the output to 8 bits from 10 bits input
analogWrite(outputPin, outputValue);
Serial.println(outputValue); // print the voltage between 0 to 5 ( in 8 bits 0 to 255)
delay(10);
}