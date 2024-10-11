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
const int push_button_pin= 4;
int buttonState=1;
int prev_buttonState=0;

void setup() {
lcd.init(); 
pinMode(push_button_pin, INPUT);
Serial.begin(9600);
}

void loop() {
buttonState= digitalRead(push_button_pin);
if (buttonState==0 and prev_buttonState==0){
lcd.backlight();
lcd.print("Welcome!!");
delay(2000);
prev_buttonState=1;
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
}
else if (buttonState==0 and prev_buttonState==1){
  prev_buttonState=0;
  lcd.clear();
  lcd.print("Shutting Down!!");
  delay(2000);
  lcd.clear();
  lcd.noBacklight();
}
}
/*
the baove does not give the live distance but only the distance each time the button is pressed.
thats becoz once it enters the loop it checks the distance only once.
*/