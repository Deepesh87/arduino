#include <Arduino.h>
/*
3 pins in the KY039 sensor, 5V, GND and an analog pin.
Just plotting the readings as received from the sensor on the Serial plot, we see there are
skipes varying between 900 and 1000. The spikes are apparently the heatbeats. We have to count them per second.
The logic is that when the heart beats fresh oxygenated blood flows and hence, the min amount of IR light
is received by the receiver and thus the max reading. as with more light the resistance increases.
reference: https://www.hackster.io/Johan_Ha/from-ky-039-to-heart-rate-0abfca
*/
int pinread=A0;
double sensor_reading;
int num_readings=5;
float pulse;
int avg_sensor_reading(int a, int b);
void setup() {
  // put your setup code here, to run once:
  pinMode(pinread, INPUT);
  Serial.begin(9600);
}

void loop() {
//take avg of 50 readings to smooth the sensor reading
sensor_reading = avg_sensor_reading(pinread, num_readings);
Serial.println(sensor_reading);
delay(200);
// identify the peaks..the values varying between 900 to 1000. I would say
// lets take 80th percentile of the numbers and consider that as a threshold.
// any sensor reading above this will be counted as 1 heartbeat. we will 
//count how mnay such heartbeats happen every second
}

int avg_sensor_reading(int pin_num, int num_of_readings){
double sensor_reading=0;
for(int i=0; i<num_of_readings; i++){
  int temp = analogRead(pin_num);
  sensor_reading+=temp;
}
sensor_reading= sensor_reading/num_of_readings;
return sensor_reading;
}