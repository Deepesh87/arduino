#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // dht has dependency on this
#include <LiquidCrystal_I2C.h>


// leftmost-- VCC, then Sensor pin, pin 3 not used, pin 4 is GND
const int sensorPin= 7; 
#define Type DHT11 //  to define the DHT sensor type you’re using
float temp;
float humidity;

DHT dht(sensorPin, Type); //initialize a DHT object with the pin and type
LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
// pinMode(sensorPin, OUTPUT); not needed, already set in the library
Serial.begin(9600);
lcd.init(); 
lcd.backlight();
dht.begin();
}

void loop() {
 temp = dht.readTemperature();
 humidity = dht.readHumidity();
 lcd.setCursor(0,0);
 lcd.print("Temp C: ");
 lcd.print(temp);
 lcd.setCursor(0,1);
 lcd.print("Humidity: ");
 lcd.print(humidity);
 delay(10);
}
