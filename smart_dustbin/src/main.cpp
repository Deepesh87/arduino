#include <Arduino.h>
#include <Servo.h>

/*
connecting a servo
Red wire is the Power. connect to 5V,
Brown is the Ground
Orange is the control, connect to Pin 9 (in this example)
DONT PRESS ENTER. IT IS TAKEN AS 0

*/

/*
==================for Ultra Sonic Sensor=====================
connect trigger pin to 12, echo pin to 11,
vcc to 5v of arduino and grn to grn of arduino
*/

int pos;
int ServoPin=9;
Servo myServo;
byte trigg_pin= 12;
byte echo_pin =11;
int travelTime;
int dist_helper=0; // plan is to calculate distance num_reading times and take action on the avg rather than individual readings.
unsigned int dist_in_cms;
unsigned int avg_distance;
int num_reading=50;
int i;

void setup() {
  // put your setup code here, to run once:
myServo.attach(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
myServo.write(180);// default position and keeps the bin closed
dist_helper=0;// to reset it to 0
// use the sonar
for (i=0; i<num_reading; i=i+1){
digitalWrite(trigg_pin, LOW);
delayMicroseconds(2);
digitalWrite(trigg_pin, HIGH); //Send ping
delayMicroseconds(10);  //Ping must remain high for 10ms to send a proper signal out.
digitalWrite(trigg_pin, LOW);  //stop ping
travelTime= pulseIn(echo_pin, HIGH); // gives the time in micro seconds
dist_in_cms= 0.017*travelTime; // calculated using distance= speed * time

// to avoid errorneous reading, we cap the max to 50 and min to 1.
if (dist_in_cms<0){
  dist_in_cms= 1;
}
if (dist_in_cms>100){
  dist_in_cms= 50;
}
dist_helper= dist_helper + dist_in_cms;
}
// take the avg distance
avg_distance= dist_helper/num_reading;
if (avg_distance< 15){
myServo.write(90); // to open the bin
delay(3000);// keep it open for 3 sec
}
}