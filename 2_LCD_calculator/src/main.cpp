#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// ask user for input from the LCD.
// user enters in the Serial monitor
// 2 numbers and the operation

/*
With the I2C module in LCD, we need just 4 pins
only the 4 pins need to be connected.
GND to gnd
VCC to 5V,
SDA to A4, SCL to A5
*/

LiquidCrystal_I2C lcd(0x27, 16,2);// 16 cols and 2 rows
// 0x27 since in my I2C, all 2 pins A0, A1 and A2 are not joined i.e. 0,0,0 refer image I2C_Address.JPG

float num1;
float num2;
float result;
String operation;

void setup() {
lcd.init(); 
lcd.backlight();
Serial.begin(9600);
}

void loop() {
lcd.setCursor(0,0);
lcd.print("Lame calculator!");
delay(2000);
lcd.setCursor(0,1);
lcd.print("Enter 1st Num   ");
Serial.println("Enter the 1st Num");
while(Serial.available()==0){
    }
num1= Serial.parseFloat();
Serial.print("1st number given: ");
Serial.println(num1);
lcd.setCursor(0,1);
lcd.print(("1st num: "+String(num1)+"         "));// added spaces at end to clear the previous string
delay(1000);
//=========
lcd.setCursor(0,1);
lcd.print("Enter 2nd Num   ");
Serial.println("Enter the 2nd Num");
while(Serial.available()==0){
    }
num2= Serial.parseFloat();
Serial.print("2nd number given: ");
Serial.println(num2);
lcd.setCursor(0,1);
lcd.print(("2nd num: "+String(num2)+"         "));// added spaces at end to clear the previous string
delay(1000);
//=========
lcd.setCursor(0,1);
lcd.print("Enter operation   ");
Serial.println("Enter the operation one of (+, -, /, *)");
while(Serial.available()==0){
    }
operation= Serial.readString();
Serial.print("Operand given is: ");
Serial.println(operation);
lcd.setCursor(0,1);
lcd.print(("Operand: "+operation+"         "));// added spaces at end to clear the previous string
delay(1000);
//=====
lcd.setCursor(0,0);
lcd.print("Result is:         ");
Serial.println("Result is: ");
if (operation=="+"){
result= num1+num2;
}
else if (operation=="-"){
result= num1-num2;
}
else if (operation=="*"){
result= num1*num2;
}
else if (operation=="/"){
result= num1/num2;
}

Serial.println(String(num1)+ operation+ String(num2)+"= "+ String(result) );
lcd.setCursor(0,1);
lcd.print(String(num1)+ operation+ String(num2)+"="+ String(result)+"        ");// added spaces at end to clear the previous string
delay(10000);
lcd.setCursor(0,1);
lcd.print("Thank You!     ");
}