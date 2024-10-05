#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // dht has dependency on this
// leftmost-- VCC, then Sensor pin, pin 3 not used, pin 4 is GND
const int sensorPin= 7; 
#define Type DHT11
float temp;
float humidity;

DHT dht(sensorPin, Type);

void setup() {
// pinMode(sensorPin, OUTPUT); not needed, already set in the library
Serial.begin(9600);
dht.begin();
}

void loop() {
 humidity = dht.readHumidity();
 temp = dht.readHumidity();
 Serial.print("Humidity = ");
 Serial.print(humidity);
 Serial.print(" ");
 Serial.print("Temperature= ");
 Serial.println(temp);
 delay(1000);
}
