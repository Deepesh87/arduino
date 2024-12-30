#include <Arduino.h>
/*
CONNECT 3 LEDS, rgb AND ASK USER WHICH COLOR HE WANTS TO LIGHT
*/

const int pinR=2;
const int pinG=3;
const int pinB=4;
int counter=0;
String name;
String color;
                    
int delaytime=600;
int pin_led_off(int x);
int pin_led_on(int x);

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
pin_led_off(pinR);
pin_led_off(pinB);
pin_led_off(pinG);
if (counter==0){
  Serial.println("What is your Name?");
  while(Serial.available()==0){
    }
  name = Serial.readString();
  Serial.print("Hello ");
  Serial.println(name);
  counter+=1;
}
Serial.println("What Color LED? ");
while(Serial.available()==0){
}
color= Serial.readString();
color.trim();// to trim the enter key
color.toLowerCase(); // TO MAKE IT CASE inSENSITIVE
Serial.print("color chosen is: ");
Serial.println(color);
if (color=="red"){
pin_led_on(pinR);
}
else if(color =="green"){
 pin_led_on(pinG); 
}
else if (color =="blue"){
 pin_led_on(pinB);  
}
delay(3000);
}

int pin_led_off(int x){
  digitalWrite(x, LOW);
}

int pin_led_on(int x){
  digitalWrite(x, HIGH);
}