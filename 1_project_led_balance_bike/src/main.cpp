#include <Arduino.h>
/*
project to have a few RBG leds on a balance bike and User would control them using a push button switch.
*/

// define the pins for the RGB leds
//first led
byte redPin = 2;
byte greenPin = 3;
byte bluePin = 4;
//second led
byte redPin2 = 6;
byte greenPin2 = 7;
byte bluePin2 = 8;
//third led
byte redPin3 = 11;
byte greenPin3 = 12;
byte bluePin3 = 13;
//pins for the push button. Will use a pull down resistor
byte buttonPin = A0;
// state 1 is RED, state 2 is BLUE, state 3 is GREEN. will start with Red
int state = 1;
int pushButtonState = 0;
// time from the begining of the loop
int time = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin3, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void loop() {
  time = millis();
  // after 20 seconds, do nothing
  if (time > 20000) { 
    state = 0;//do nothing since we dont have a case for state 0 below
  }
  // read the state of the push button
  pushButtonState = digitalRead(buttonPin);
  delay(200);
  // if the button is pressed, change the state of the leds
  if (pushButtonState == HIGH) {
    state++;
    if (state > 7) {
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
      //turn on the third led RED
      digitalWrite(redPin3, HIGH);
      digitalWrite(greenPin3, LOW);
      digitalWrite(bluePin3, LOW);
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
      //turn on the third led BLUE
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, LOW);
      digitalWrite(bluePin3, HIGH);
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
      //turn on the third led GREEN
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, HIGH);
      digitalWrite(bluePin3, LOW);
      break;
    case 4:
      //do a colorful chase
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, LOW);
      digitalWrite(bluePin3, HIGH); 
      break;
    case 5:
      //do a colorful chase 2
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, LOW);
      digitalWrite(bluePin3, HIGH); 
      break;
    case 6:
      //do a colorful chase 3
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, HIGH);
      digitalWrite(bluePin3, LOW); 
      break;
    case 7:
      //turn off all the leds
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin3, LOW);
      digitalWrite(greenPin3, LOW);
      digitalWrite(bluePin3, LOW);
      break;
  }
}

