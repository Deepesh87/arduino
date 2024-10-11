#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/*
======= for LCD=========================
only the 4 pins need to be connected.
GND to gnd
VCC to 5V,
SDA to A4, SCL to A5
*/
LiquidCrystal_I2C lcd(0x27, 16,2);// 16 cols and 2 rows
// 0x27 since in my I2C, all 2 pins A0, A1 and A2 are not joined i.e. 0,0,0 refer image I2C_Address.JPG
/*
==================for Ultra Sonic Sensor=====================
connect trigger pin to 12, echo pin to 11,
vcc to 5v of arduino and grn to grn of arduino
*/
const int trigg_pin= 12;
const int echo_pin =11;
int travelTime;
int dist_in_cms=0;

void setup() {
lcd.init(); 
lcd.backlight();
}

void loop() {
digitalWrite(trigg_pin, LOW);
delayMicroseconds(2);
digitalWrite(trigg_pin, HIGH); //Send ping
delayMicroseconds(10);  //Ping must remain high for 10ms to send a proper signal out.
digitalWrite(trigg_pin, LOW);  //stop ping
travelTime= pulseIn(echo_pin, HIGH); // gives the time in micro seconds
dist_in_cms= 0.017*travelTime; // calculated using distance= speed * time
lcd.setCursor(0,0);
lcd.print("Distance in cms: ");
lcd.setCursor(0,1);
lcd.print(dist_in_cms);
delay(1000);
lcd.clear();
}