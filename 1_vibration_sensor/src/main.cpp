#include <Arduino.h>

// SW-420 Vibration Sensor Module 
// will turn on an LED light when the sensor detects vibration
// led positive is connected to pin 8 of the Arduino board with a resistor of 330 Ohm in series

// The sensor data pin is connected to the digital pin 10 of the Arduino board

byte led_pin = 8;
byte sensor_pin = 9;
bool sensor_value = 0;


void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
sensor_value = digitalRead(sensor_pin);
Serial.println(sensor_value);
if (sensor_value == 1) {
  digitalWrite(led_pin, HIGH);
  delay(5000);
  digitalWrite(led_pin, LOW);
  delay(1000);
}
else {
  digitalWrite(led_pin, LOW);
}
}

