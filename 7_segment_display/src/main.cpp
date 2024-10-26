#include <Arduino.h>
#include <SevSeg.h>
/*
countdown timer on a single digit 7 segment display.
for information on how to connect the PINS, refer the image attached here
Use 220 to 330 Ohn resistor for each segment.
*/
SevSeg sevseg;//create object
byte num_digits = 1; // num of digits in display
byte digit_pins[] = {};// not used with single digit display
byte segment_pins[] = {6,5,2,3,4,7,8,9}; // in order of A,B,C,D,E,F,G, decimal
bool resistors_used = true;
byte hardware_config = COMMON_CATHODE;
void setup() {
sevseg.begin(hardware_config, num_digits, digit_pins, segment_pins, resistors_used);
sevseg.setBrightness(90);
}
void loop() {
  //countdown
for(int i=0;  i < 10; i++){
sevseg.setNumber(i);
delay(500);
sevseg.refreshDisplay();  
}
// display letters A to F (hexadecimal chars)
sevseg.setChars("A");
 delay(500);
sevseg.refreshDisplay();
 delay(500); 
sevseg.setChars("B");
 delay(500);
sevseg.refreshDisplay(); 
sevseg.setChars("C");
 delay(500);
sevseg.refreshDisplay(); 
sevseg.setChars("D");
 delay(500);
sevseg.refreshDisplay(); 
sevseg.setChars("E");
 delay(500);
sevseg.refreshDisplay(); 
sevseg.setChars("F");
 delay(500);
 sevseg.refreshDisplay(); 
}
