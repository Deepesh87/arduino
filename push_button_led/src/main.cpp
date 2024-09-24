#include <Arduino.h>
/*
pin 2 will be the input pin, this will read input from the 5V,
If it reads 5 V pin 2 will be HIGH else to Grund or LOW.
PIN 12 will be the output pin and read input from board, either HIGH or LOW
see diagram for more understanding
*/

// put function declarations here:
const int pushButtonPIn=2;
const int pin_led=12;
int buttonState=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushButtonPIn, INPUT);
  pinMode(pin_led, OUTPUT);
}

void loop() {
int buttonState= digitalRead(pushButtonPIn);
if (buttonState==HIGH){
digitalWrite(pin_led, HIGH);
}
else{
 digitalWrite(pin_led, LOW); 
}
}


/*
we use a pull down resistr here with the button . (Negative is connected to resistor)
See https://youtu.be/AgQW81zzR18?si=DmK0A75XFu2ttHsZ
when button is not pressed, the entire 5V that it is reading should go to the Ground,
So, we should connect the button to also GROUND.  
https://youtu.be/yBgMJssXqHY?si=W9xHePXHBlov84TN
*/