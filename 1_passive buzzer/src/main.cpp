#include <Arduino.h>
// play random sounds that change with a passive buzzer.

int buzzPin= 8;
int passive_buzz_tune(int buzzPin);

void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
}


void loop() {
passive_buzz_tune(buzzPin);
}

// put function definitions here:
int passive_buzz_tune(int x) {
tone(x,440);
delay(500);
tone(x,494);
delay(500);
tone(x,523);
delay(500);
tone(x,587);
delay(500);
tone(x,659);
delay(500);
tone(x,587);
delay(500);
tone(x,523);
delay(500);
tone(x,494);
delay(500);
tone(x,440);
delay(500);
}