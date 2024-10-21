#include <Arduino.h>
#include <IRremote.h>
/*
program to map the HEX code for all buttons on a IR remote
using the latest version of library. so these functions may not be on most youtube videos
IR sensor connection- when S is written on the right..
left to GND,
Middle to 5V,
right to pin
*/

const int ir_pin=9;
String mycom;

void setup() {
Serial.begin(9600);
IrReceiver.begin(ir_pin, false); // IrReceiver is the object that the library gives. 
}

void loop() {
if (IrReceiver.decode()){   // this is true only when a data is received
mycom = String(IrReceiver.decodedIRData.decodedRawData, HEX);
switch(IrReceiver.decodedIRData.decodedRawData)  // switch can only take non String, so directly using the raw output
{
case 0xba45ff00:
    Serial.println("Pressed 1");
    break;
case 0xb946ff00:
    Serial.println("Pressed 2");
    break;
case 0xb847ff00:
    Serial.println("Pressed 3");
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
    break;
case 0xf20dff00:
    Serial.println("Pressed #");
    break;
case 0xe31cff00:
    Serial.println("Pressed OK");
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
IrReceiver.resume();
}
}


