#include <Arduino.h>

const int lightPin=A0;
const int redLight_pin=2;
const int greenLight_pin=7;
int lightValue=0;

void setup() {
  // put your setup code here, to run once:
pinMode(lightPin, INPUT);
pinMode(redLight_pin, OUTPUT);
pinMode(greenLight_pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
lightValue=analogRead(lightPin);
Serial.println(lightValue);

}
