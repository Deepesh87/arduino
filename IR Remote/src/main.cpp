#include <Arduino.h>
#include <IRremote.h>


const int ir_pin=9;
IRrecv IR(ir_pin);
decode_results cmd;

void setup() {
Serial.begin(9600);
IR.enableIRIn();
IR.blink13(true);
}

void loop() {
  while(IR.decode(&cmd)==0){
}
Serial.println(cmd.value, HEX);
delay(1500);
IR.resume();
}

