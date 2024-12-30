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
  Serial.begin(9600);
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

/* ==========detailed explanation here===========
1) currentButtonState or the input always gives 0. As soon as the pin is pressed it becomes 1 and goes in the If condition
2) in the IF Condition it does its stuff and as as soon as it comes out 
3) currentButtonState becomes 0 since the PIN is not still pressed, so oldButtonState will always read 0
*/
