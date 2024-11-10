#include <Arduino.h>
/*
2 push buttons one to increase brightness other to decrease. 
both in steps of say (50).
when min brightness i.e. 0 is reached or max brightness i.e. 255 is reached,
sound the buzzer, so user stops pressing.
*/
const int pin_read_increase= 7;
const int pin_read_decrease= 2;
const int led_pin=9;
const int buzzer_pin=4;
int led_brightness=0;

void setup()
{
  pinMode(pin_read_increase, INPUT);
  pinMode(pin_read_decrease, INPUT);
  pinMode(led_pin, OUTPUT); 
  pinMode(buzzer_pin, OUTPUT);   
  Serial.begin(9600);
}

void loop()
{
int increase_button_state= digitalRead(pin_read_increase);
int decrease_button_state= digitalRead(pin_read_decrease);
Serial.print("brightness value "); 
Serial.print(led_brightness); 
Serial.println("");
delay(250);
  if (increase_button_state ==1){
    led_brightness+=50;
    if (led_brightness>255){
      digitalWrite(buzzer_pin, HIGH);
      delay(2400);
      digitalWrite(buzzer_pin, LOW); 
      led_brightness=255;
    }
  }
  if (decrease_button_state ==1){
    led_brightness-=50;
      if (led_brightness<0){
      digitalWrite(buzzer_pin, HIGH);      
      delay(3000);
      digitalWrite(buzzer_pin, LOW); 
      led_brightness=0;
    }
  }   
    analogWrite(led_pin,led_brightness);  
}