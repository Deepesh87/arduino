#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // dht has dependency on this
#include <LiquidCrystal_I2C.h>



/*
get started with the DHT11 temp & humidity sensor.BUT this time isplay on an LCD
USe 16*2 LCD with the I2C Module.
I2CModule ---> GND, VCC, SDA, SCL. SDA to A4, SCL to A5 [ these are defaults and need not be specified]
DHT11     ---> leftmost-- VCC, then Sensor pin, pin 3 not used, pin 4 is GND
*/



const int sensorPin= 7; 
#define Type DHT11 //  to define the DHT sensor type you’re using
float temp;
float humidity;

DHT dht(sensorPin, Type); //initialize a DHT object with the pin and type
LiquidCrystal_I2C lcd(0x27, 16,2); //0*27 since all A0, A1 and A2 are not joined (See image)

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
