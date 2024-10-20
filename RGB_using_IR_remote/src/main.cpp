#include <Arduino.h>
#include <IRremote.h>
/*
ok button to give me white LED,
each buttton from 1 to 9 to give me different colors.
down button to reduce brightness in steps until min, similarly, up button to increase brightness
to max. brighteness settign to stay same on change of color.
0 button to bring back to white color with pre exisiting brightness settings
*/

const int PinR= 3;
const int PinG= 5;
const int PinB= 6;
const int PinIR= 9;
String mycom;
const int max_state=255;
int glow_rgb(int x, int y, int z);
int red_state=0;
int green_state=0;
int blue_state=0;
int last_red_state=0;
int last_green_state=0;
int last_blue_state=0;

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
switch(IrReceiver.decodedIRData.decodedRawData)  // switch can only take non int, so directly using the raw output
{
case 0xba45ff00:
    Serial.println("Pressed 1");
    red_state=255;
    green_state=0;
    blue_state=0;
    glow_rgb(red_state, green_state, blue_state);
    break;
case 0xb946ff00:
    Serial.println("Pressed 2");
    red_state=0;
    green_state=255;
    blue_state=0;
    glow_rgb(red_state, green_state, blue_state);   
    break;
case 0xb847ff00:
    Serial.println("Pressed 3");
    red_state=0;
    green_state=0;
    blue_state=255;
    glow_rgb(red_state, green_state, blue_state);
    break;
case 0xbb44ff00:
    Serial.println("Pressed 4");
    break;
case 0xbf40ff00:
    Serial.println("Pressed 5");
    break;
case 0xbc43ff00:
    Serial.println("Pressed 6");
    break;   
case 0xf807ff00:
    Serial.println("Pressed 7");
    break;
case 0xea15ff00:
    Serial.println("Pressed 8");
    break;
case 0xf609ff00:
    Serial.println("Pressed 9");
    break;
case 0xe916ff00:
    Serial.println("Pressed *");
    break; 
case 0xe619ff00:
    Serial.println("Pressed 0");
    glow_rgb(red_state, green_state, blue_state); 
    break;
case 0xf20dff00:
    Serial.println("Pressed #");
    break;
case 0xe31cff00:
    Serial.println("Pressed OK");
    glow_rgb(red_state, green_state, blue_state);
    break;   
case 0xf708ff00:
    Serial.println("Pressed left");
    break;
case 0xa55aff00:
    Serial.println("Pressed right");
    break;
case 0xe718ff00:
    Serial.println("Pressed FWD");
    break;
case 0xad52ff00:
    Serial.println("Pressed BACK");
    break; 
default:
    Serial.println("Not sure what key did you press?");
}
delay(1500);

if (IrReceiver.decodedIRData.decodedRawData==0xad52ff00){ // down arrow key is pressed
    if (red_state>0){
    red_state= max(red_state-50,0);
    }
    if (green_state>0){
    green_state = max(green_state-50,0);
    }
    if (blue_state>0){
    blue_state = max(blue_state -50,0);
    }    
    glow_rgb(red_state, green_state, blue_state);
}
if (IrReceiver.decodedIRData.decodedRawData==0xe718ff00){ // UP arrow key is pressed
    if (red_state>0){
    red_state= min(red_state+50,255);
    }
    if (green_state>0){
    green_state= min(green_state+50,255);
    }
    if (blue_state>0){
    blue_state= min(blue_state+50,255);
    }
    glow_rgb(red_state, green_state, blue_state);
}
last_red_state = red_state;
last_green_state = green_state;
last_blue_state = blue_state;
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
