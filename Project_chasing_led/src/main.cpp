#include <Arduino.h>
const int pin1=2;
const int pin2=3;
const int pin3=4;
const int pin4=5;
const int pin5=6;
const int pin6=7;
const int pin7=8;
const int pin8=9;
const int pin9=10;
const int pin10=11;
const int pin11=12;
int glow_stop_delay(int pin_num, int delay_time);
int delay_time=30;
int counter=0;

void setup() {
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);
pinMode(pin7, OUTPUT);
pinMode(pin8, OUTPUT);
pinMode(pin9, OUTPUT);
pinMode(pin10, OUTPUT);
pinMode(pin11, OUTPUT);
}

void loop() {
glow_stop_delay(pin1,delay_time);
glow_stop_delay(pin2,delay_time);
glow_stop_delay(pin3,delay_time);
glow_stop_delay(pin4,delay_time);
glow_stop_delay(pin5,delay_time);
glow_stop_delay(pin6,delay_time);
glow_stop_delay(pin7,delay_time);
glow_stop_delay(pin8,delay_time);
glow_stop_delay(pin9,delay_time);
glow_stop_delay(pin10,delay_time);
glow_stop_delay(pin11,delay_time);
glow_stop_delay(pin10,delay_time);
glow_stop_delay(pin9,delay_time);
glow_stop_delay(pin8,delay_time);
glow_stop_delay(pin7,delay_time);
glow_stop_delay(pin6,delay_time);
glow_stop_delay(pin5,delay_time);
glow_stop_delay(pin4,delay_time);
glow_stop_delay(pin3,delay_time);
glow_stop_delay(pin2,delay_time);
glow_stop_delay(pin1,delay_time);
delay(delay_time*2);
//glow color wise
//blue
glow_stop_delay(pin2,delay_time*3);
glow_stop_delay(pin5,delay_time*3);
glow_stop_delay(pin8,delay_time*3);
glow_stop_delay(pin11,delay_time*3);
//red
glow_stop_delay(pin1,delay_time*3);
glow_stop_delay(pin4,delay_time*3);
glow_stop_delay(pin6,delay_time*3);
glow_stop_delay(pin9,delay_time*3);
//green
glow_stop_delay(pin3,delay_time*3);
glow_stop_delay(pin7,delay_time*3);
glow_stop_delay(pin10,delay_time*3);
delay(delay_time*10);
// from both sides
glow_stop_delay(pin1,delay_time*3);
glow_stop_delay(pin11,delay_time*3);
glow_stop_delay(pin2,delay_time*3);
glow_stop_delay(pin10,delay_time*3);
glow_stop_delay(pin3,delay_time*3);
glow_stop_delay(pin9,delay_time*3);
glow_stop_delay(pin4,delay_time*3);
glow_stop_delay(pin8,delay_time*3);
glow_stop_delay(pin5,delay_time*3);
glow_stop_delay(pin7,delay_time*3);
glow_stop_delay(pin6,delay_time*3);
}




int glow_stop_delay(int pin_num, int delay_time){
  digitalWrite(pin_num,HIGH);
  delay(delay_time);
  digitalWrite(pin_num,LOW);
  delay(delay_time);  
  return 0; 
}


