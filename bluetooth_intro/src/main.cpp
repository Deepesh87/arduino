#include <Arduino.h>

/*
get started controlling using a bluetooth. in this example we will
light an LED, using commands from a bleutooth device.
In the code, if we type H in the Serial command, it should lighten up the bulb.
use the app Arduino Bluetooth App on Android.
*/

char val; // variable to receive data from bluetooth connection
const int led_pin = 7;

void setup()
{
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
  }
  if (val == 'H')
  {
    digitalWrite(led_pin, HIGH);
  }
  else
  {
    digitalWrite(led_pin, LOW);
  }
}
