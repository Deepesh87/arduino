#include <Arduino.h>
/*
pin 2 will be the input pin, this will read input from the 5V,
If it reads 5 V pin 2 will be HIGH else to Grund or LOW.
PIN 12 will be the output pin and read input from board, either HIGH or LOW
see diagram for more understanding. Same image as push_button_led code
*/

// put function declarations here:
const int pushButtonPIn=2;
const int pin_led=12;
int currentButtonState=0;
int oldButtonState=0;
int led_state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushButtonPIn, INPUT);
  pinMode(pin_led, OUTPUT);
}

void loop() {
currentButtonState= digitalRead(pushButtonPIn);
if (oldButtonState==0 && currentButtonState==1){
  if (led_state==0){
    digitalWrite(pin_led, HIGH);
    led_state=1;
}
  else{
    digitalWrite(pin_led, LOW);
    led_state=0;
  }
}
oldButtonState= currentButtonState;
delay(100);
}


