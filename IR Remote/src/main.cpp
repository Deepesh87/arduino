#include <Arduino.h>
#include <IRremote.h>
/*
program to view the HEX code for all buttons on a IR remote

*/

const int ir_pin=9;
IRrecv IR(ir_pin); // create an IR object and give the pin number
decode_results cmd; // command from library to read the results from the remote and save in a variable

void setup() {
Serial.begin(9600);
IR.enableIRIn();
IR.blink13(true);
}

void loop() {
  while(IR.decode(&cmd)==0){   //call the value stored at this variable cmd using &
}
Serial.println(cmd.value, HEX);
delay(1500);
IR.resume();
}


