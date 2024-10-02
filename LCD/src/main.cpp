#include <Arduino.h>
#include <LiquidCrystal.h>

/*vss goes to ground,
vdd-5v,
v0 - middleof potentiometer,
rs- pin 7
rw-gnd,
E - 8,
*/

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
lcd.begin(16,2); // 16 cols and 2 rows

}

void loop() {
lcd.setCursor(0,0);
lcd.print("Watch me count!");
for (int i=0; i<=100; i=i+1){
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(500);
}
lcd.clear();
}