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
Serial.println(mycom);
delay(1500);
IrReceiver.resume();
}
}


