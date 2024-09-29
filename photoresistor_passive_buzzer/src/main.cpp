#include <Arduino.h>

/*
build a buzzer that changes the tone with variations of light.
less light less buzz, more light more buzz
*/
// put function declarations here:
int buzzPin= 8;
int light_sensor_pin= A0;
int light_value=0;

void setup() {
  // put your setup code here, to run once:
pinMode(light_sensor_pin, INPUT);
pinMode(buzzPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
light_value= analogRead(light_sensor_pin);
Serial.println(light_value);
if (light_value<100){
tone(buzzPin, 440);
delay(800);
}
else if (light_value<300){
tone(buzzPin, 494);
delay(800);
}
else if (light_value<600){
tone(buzzPin, 523);
delay(800);
}
else if (light_value<800){
tone(buzzPin, 587);
delay(800);
}
else{
tone(buzzPin, 659);
delay(800);
}
}