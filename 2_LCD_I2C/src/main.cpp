#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/*
only the 4 pins need to be connected.
GND to gnd
VCC to 5V,
SDA to A4, SCL to A5
*/
LiquidCrystal_I2C lcd(0x27, 16,2);// 16 cols and 2 rows
// 0x27 since in my I2C, all 2 pins A0, A1 and A2 are not joined i.e. 0,0,0 refer image I2C_Address.JPG

void setup() {
lcd.init(); 
lcd.backlight();
}

void loop() {
lcd.setCursor(0,0);
lcd.print("Watch me count!");
for (int i=0; i<=100; i=i+1){
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(200);
}
lcd.clear();
}