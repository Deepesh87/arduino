#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // dht has dependency on this
// leftmost-- VCC, then Sensor pin, pin 3 not used, pin 4 is GND
const int sensorPin= 7; 
#define Type DHT11 //  to define the DHT sensor type you’re using
float temp;
float humidity;

DHT dht(sensorPin, Type); //initialize a DHT object with the pin and type

void setup() {
// pinMode(sensorPin, OUTPUT); not needed, already set in the library
Serial.begin(9600);
dht.begin();
}

void loop() {
 humidity = dht.readHumidity();
 temp = dht.readTemperature();
 Serial.print("Humidity = ");
 Serial.print(humidity);
 Serial.print(" ");
 Serial.print("Temperature= ");
 Serial.println(temp);
 delay(1000);
}
