#include <Arduino.h>
/*
project to have a few RBG leds on a balance bike and User would control them using a push button switch.
*/

// define the pins for the RGB leds
//first led
byte redPin = 3;
byte greenPin = 4;
byte bluePin = 5;
//second led
byte redPin2 = 8;
byte greenPin2 = 9;
byte bluePin2 = 10;
//pins for the push button. Will use a pull down resistor
byte buttonPin = 13;
// state 1 is RED, state 2 is BLUE, state 3 is GREEN. will start with Red
int state = 1;
int pushButtonState = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the push button
  pushButtonState = digitalRead(buttonPin);
  delay(500);
  // if the button is pressed, change the state of the leds
  if (pushButtonState == HIGH) {
    state++;
    if (state > 3) {
      state = 1;
    }
  }
  // change the color of the leds based on the state
  switch (state) {
    case 1:
      //turn on the first led RED
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      //turn on the second led RED
      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);
      break;
    case 2:
      //turn on the first led BLUE
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      //turn on the second led BLUE
      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, HIGH);
      break;
    case 3:
      //turn on the first led GREEN
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      //turn on the second led GREEN
      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, LOW);
      break;
  }
}

