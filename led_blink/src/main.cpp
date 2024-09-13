#include <Arduino.h>


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);// LED_BUILTIN is a function that refers to pin 13
                                // PinMode is a function that is used to asign a pin as an output/input
}

void loop() {
digitalWrite(LED_BUILTIN, HIGH); // digitalWrite is used to write a HIGH/Low or On/Off signal to a pin
delay(1000);
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
}
