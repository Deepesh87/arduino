#include <Arduino.h>
#include <IRremote.h>
/*
ok button to give me white LED,
each buttton from 1 to 9 to give me different colors.
down button to reduce brightness in steps until min, similarly, up button to increase brightness
to max. brighteness settign to stay same on change of color.
0 button to bring back to white color with pre exisiting brightness settings
*/

const int PinR= 10;
const int PinG= 5;
const int PinB= 6;
const int PinIR= 9;
String mycom;
int glow_rgb(int x, int y, int z);
int red_state=0;
int green_state=0;
int blue_state=0;
int brightness=255; 

void setup() {
pinMode(PinR, OUTPUT);
pinMode(PinG, OUTPUT);
pinMode(PinB, OUTPUT);
IrReceiver.begin(PinIR, false); // IrReceiver is the object that the library gives.
Serial.begin(9600); 
}

void loop() {
if (IrReceiver.decode()){   // this is true only when a data is received
mycom = String(IrReceiver.decodedIRData.decodedRawData, HEX);
switch(IrReceiver.decodedIRData.decodedRawData)  // switch can only take non String, so directly using the raw output
{
case 0xba45ff00:
    Serial.println("Pressed 1");
    red_state=brightness;
    green_state=0;
    blue_state=0;
    break;
case 0xb946ff00:
    Serial.println("Pressed 2");
    red_state=0;
    green_state=brightness;
    blue_state=0;
    break;
case 0xb847ff00:
    Serial.println("Pressed 3");
    red_state=0;
    green_state=0;
    blue_state=brightness;
    break;
case 0xe718ff00:
    Serial.println("Pressed UP");
    if((red_state<255) & (red_state>0)){
    brightness = min(brightness +100,255); 
    red_state= brightness;
    }
    if((green_state<255) & (green_state>0)){
    brightness = min(brightness +100,255); 
    green_state= brightness;
    }
    if((blue_state<255) & (blue_state>0)){
    brightness = min(brightness +100,255); 
    blue_state= brightness;
    }
    break;
case 0xad52ff00:
    Serial.println("Pressed DOWN");
    if(red_state>0){
    brightness = max(brightness -100, 1); 
    red_state= brightness;
    }
    if(green_state>0){
    brightness = max(brightness -100, 1); 
    green_state= brightness;
    }
    if(blue_state>0){
    brightness = max(brightness -100, 1);  
    blue_state= brightness;
    }
    break; 
default:
    Serial.println("Not sure what key did you press?");
}

glow_rgb(red_state, green_state, blue_state);
delay(1500);

Serial.println(red_state);
Serial.println(green_state);
Serial.println(blue_state);
IrReceiver.resume();
}
}

int glow_rgb(int red, int green, int blue){
  analogWrite(PinR,red); 
  analogWrite(PinG,green); 
  analogWrite(PinB,blue); 
  return 0;
}
