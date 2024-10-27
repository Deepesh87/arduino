#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72xx::GENERIC_HW // other option is PAROLA_HW , GENERIC_HW, FC_16HW
#define MAX_DEVICES 1
#define CS_PIN 3
#define CLK_PIN 12
#define DATA_PIN 11

MD_PAROLA my_display = MD_PAROLA(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  my_display.begin();
  my_display.setIntensity(1);
  my_display.displayClear();
}

void loop() {
  // align LEFT
my_display.setTextAlignment(PA_LEFT);
my_display.print("1");
delay(2000);
  // align center
my_display.setTextAlignment(PA_CENTER);
my_display.print("2");
delay(2000);
  // align right
my_display.setTextAlignment(PA_RIGHT);
my_display.print("3");
delay(2000);
}