#include <Arduino.h>
#include <LiquidCrystal.h>

// vss goes to ground, vdd-5v, v0-middleof potentiometer, rw-gnd, 
int rs=12;
int en=11;
int d4=5;
int d5=4;
int d6=3;
int d7=2;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
lcd.begin(16,2); // 16 cols and 2 rows
lcd.print("Hello World!");
}

void loop() {
lcd.setCursor(0,1);
lcd.print(millis()/1000);
}