#include <Arduino.h>

/*
Print distance on Serial monitor using the Ultra Sonic Sensor.
connect trigger pin to 12, echo pin to 11,
vcc to 5v of arduino and grn to grn of arduino
*/
const int trig_pin=12;
const int echo_pin=11;
int travelTime=0;
int max_distance=200;
int dist_in_cms=0;

void setup() {
pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trig_pin, LOW); //Make sure ultrasound is off
delayMicroseconds(2);
digitalWrite(trig_pin, HIGH); //Send ping
delayMicroseconds(10);  //Ping must remain high for 10ms to send a proper signal out.
digitalWrite(trig_pin, LOW);  //stop ping
travelTime= pulseIn(echo_pin, HIGH); // gives the time in micro seconds
dist_in_cms= 0.017*travelTime; // calculated using distance= speed * time
Serial.print(" the distance of the board in cms is: ");
Serial.println(dist_in_cms);
delay(1000);
}
