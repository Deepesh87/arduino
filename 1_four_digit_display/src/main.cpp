#include <Arduino.h>
#include <SevSeg.h>
/*
countdown timer on a 4 digit 7 segment display.
for information on how to connect the PINS, refer the image attached here
Use 220-330Ohm resistor for each display select lines. Refer image.
Problem:-- I want to dispay a stop watch like 000.0 (first 000 is seconds and next 0 is deciseconds)
example: 009.9 then 001.0, 19.9 then 20.0 etc will count till 999 seconds.
*/
SevSeg sevseg; //Instantiate a seven segment controller object
static int deciSeconds = 0; // 10 deciseconds is 1 sec

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] =  {9,2,3,5,6,8,7,4}; // in order of A,B,C,D,E,F,G,Decimal
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis(); //timer is always 0 in each run
 if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond, So, 10 decisec is 1 sec    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
  sevseg.refreshDisplay(); // Must run repeatedly
}

/*
millis() - Returns the number of milliseconds passed since the Arduino
 board began running the current program (from first round of the loop)

*/