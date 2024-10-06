#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // dht has dependency on this
#include <LiquidCrystal_I2C.h>

/*
when clicked, turn on and then when clicked turn off.
*/

// leftmost-- VCC, then Sensor pin, pin 3 not used, pin 4 is GND
const int sensorPin= 7; 
const int pushButton=2;
int buttonState=0;
int previousbuttonState=0;
#define Type DHT11 //  to define the DHT sensor type you’re using
float temp;
float humidity;

DHT dht(sensorPin, Type); //initialize a DHT object with the pin and type
LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
// pinMode(sensorPin, OUTPUT); not needed, already set in the library
pinMode(pushButton, INPUT);
lcd.init(); 
dht.begin();
}

void loop() {
 buttonState= digitalRead(pushButton);
 if (buttonState==0 and previousbuttonState==0){// when lcd is off, turn it on
 lcd.backlight();
 previousbuttonState = 1;
 temp = dht.readTemperature();
 humidity = dht.readHumidity();
 lcd.setCursor(0,0);
 lcd.print("Temp C: ");
 lcd.print(temp);
 lcd.setCursor(0,1);
 lcd.print("Humidity: ");
 lcd.print(humidity);
 delay(1000);
 }
 else if (buttonState==0 and previousbuttonState==1){ // if it was previously on, turn it off
  previousbuttonState = 0;
  lcd.clear();
  lcd.noBacklight();
  delay(1000);
 }
}
