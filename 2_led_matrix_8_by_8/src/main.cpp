#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

/*
make sure to follow the image shown. Connect the pins as mentioned in variable declaration
VCC to pwoer/5V and gnd to gnd.
No resistors needed

*/

#define HARDWARE_TYPE MD_MAX72XX:: FC16_HW // other options are PAROLA_HW , GENERIC_HW, ICSTATION_HW, FC1_6HW
#define MAX_DEVICES 4 // there are 4 displays
#define CS_PIN 10
#define CLK_PIN 13
#define DATA_PIN 11

// Text to scroll
const char* text = "Welcome to Xperio Learnings!!!";

MD_Parola my_display = MD_Parola( HARDWARE_TYPE, CS_PIN, MAX_DEVICES );

void setup() {
  my_display.begin();
  my_display.setIntensity(5);// Set brightness (0-15)
  my_display.displayClear();
}


void loop() {
  my_display.displayText(text, PA_LEFT, 60, 500, PA_SCROLL_LEFT, PA_FADE); 
  // PA_LEFT - left aligned, 60 is scroll speed, 60 is pause time in ms,
  // PA_SCROLL_LEFT is scroll to left, PA_FADE is an effect
  // Wait for the animation to finish before starting again
  while (!my_display.displayAnimate()) {
  }
}

//my_display.displayAnimate() return true if When the animation has completed for the current text display.



// ====== the below code also works replace the above void function with the below.
// void loop() {
// my_display.displayAnimate();
//   // align LEFT
// my_display.setTextAlignment(PA_LEFT);
// my_display.print(text);
// delay(2000);
//   // align center
// my_display.setTextAlignment(PA_CENTER);
// my_display.print("B C");
// delay(2000);
//   // align right
// my_display.setTextAlignment(PA_RIGHT);
// my_display.print("X Y Z");
// delay(2000);
// }