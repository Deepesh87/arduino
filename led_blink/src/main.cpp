#include <Arduino.h>
/*
see image for board setup
put a led in a bread baord. connect pin 13 to a resistor of 330 Ohm. Ground the other side
this will blink both the inbuilt LED and the external LED
*/
int ledPin=13;

void setup() {
  pinMode(ledPin, OUTPUT);                               
}

void loop() {

digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);

}
