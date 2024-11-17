#include <Arduino.h>
#include <Servo.h>
#include <AFMotor.h>

// all functions and objects
void (forward());
void (back());
void(left());
void(right());
void(Stop());
int (get_distance());
int (check_direction());
Servo myServo; // define servo object
// all gear motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); // for my connection this is front RHS
AF_DCMotor motor2(2, MOTOR12_1KHZ); // for my connection this is rear RHS
AF_DCMotor motor3(3, MOTOR34_1KHZ); // for my connection this is rear LHS
AF_DCMotor motor4(4, MOTOR34_1KHZ); // for my connection this is front LHS

// define servo pins/parameters
int angle_to_turn; // angle to turn when it encounters an obstacle in gng straight
byte ServoPin=9; // control pin of servo, the other 2 are 5v and GND

// define pins/parameters for Sonic sensor
const byte trig_pin=A0; // sicne digital pins were not available on motor shield
const byte echo_pin=A5; // ended up using the analog pins
float travelTime;
int current_distance;
int set_motor_speed=160;
int speed_offset = 80; // used while taking turns to give extra power and speed
int max_distance=200;// objects beyond this ditance are ignored.
int stop_distance =40; // in cms
int dist_in_cms=0;


void setup() {
  myServo.attach(ServoPin);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Stop();
  Serial.begin(9600);
}

void loop() {
myServo.write(90); // adjust this so Servo looks right ahead
delay(500);

while(true){
current_distance = get_distance(); // Get distance continuously
if (current_distance < stop_distance) {
  Stop();  // Stop immediately if an obstacle is detected ahead
  angle_to_turn = check_direction();  // Determine which direction to turn
  break;  // Exit while loop to handle turning
}else {
forward();  // Keep moving forward if no obstacle is detected
delay(200);  // Check the distance every 200ms while moving
}
}

  // Handling the turn after stopping
  switch (angle_to_turn) {
    case 0:
      left();
      delay(800);  // turn left
      break;
    case 2:
      right();
      delay(800);  // turn right
      break;
    case 1:
      left();
      delay(1600);  // turn left more if both directions blocked
      break;
  }
}

void forward()
{
  motor1.setSpeed(set_motor_speed); // Define maximum velocity
  motor1.run(FORWARD);  // rotate the motor clockwise
  motor2.setSpeed(set_motor_speed); // Define maximum velocity
  motor2.run(FORWARD);  // rotate the motor clockwise
  motor3.setSpeed(set_motor_speed); // Define maximum velocity
  motor3.run(FORWARD);  // rotate the motor clockwise
  motor4.setSpeed(set_motor_speed); // Define maximum velocity
  motor4.run(FORWARD);  // rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(set_motor_speed); // Define maximum velocity
  motor1.run(BACKWARD); // rotate the motor anti-clockwise
  motor2.setSpeed(set_motor_speed); // Define maximum velocity
  motor2.run(BACKWARD); // rotate the motor anti-clockwise
  motor3.setSpeed(set_motor_speed); // Define maximum velocity
  motor3.run(BACKWARD); // rotate the motor anti-clockwise
  motor4.setSpeed(set_motor_speed); // Define maximum velocity
  motor4.run(BACKWARD); // rotate the motor anti-clockwise
}

void right()
{
  motor1.setSpeed(set_motor_speed+speed_offset); // Define maximum velocity
  motor1.run(BACKWARD); // rotate the motor anti-clockwise
  motor2.setSpeed(set_motor_speed+speed_offset); // Define maximum velocity
  motor2.run(BACKWARD); // rotate the motor anti-clockwise
  motor3.setSpeed(set_motor_speed); // Define maximum velocity
  motor3.run(FORWARD);  // rotate the motor clockwise
  motor4.setSpeed(set_motor_speed); // Define maximum velocity
  motor4.run(FORWARD);  // rotate the motor clockwise
}

void left()
{
  motor1.setSpeed(set_motor_speed); // Define maximum velocity
  motor1.run(FORWARD);  // rotate the motor clockwise
  motor2.setSpeed(set_motor_speed); // Define maximum velocity
  motor2.run(FORWARD);  // rotate the motor clockwise
  motor3.setSpeed(set_motor_speed+speed_offset); // Define maximum velocity
  motor3.run(BACKWARD); // rotate the motor anti-clockwise
  motor4.setSpeed(set_motor_speed+speed_offset); // Define maximum velocity
  motor4.run(BACKWARD); // rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0);  // Define minimum velocity
  motor1.run(RELEASE); // stop the motor when release the button
  motor2.setSpeed(0);  // Define minimum velocity
  motor2.run(RELEASE); // rotate the motor clockwise
  motor3.setSpeed(0);  // Define minimum velocity
  motor3.run(RELEASE); // stop the motor when release the button
  motor4.setSpeed(0);  // Define minimum velocity
  motor4.run(RELEASE); // stop the motor when release the button
}

int get_distance(){
digitalWrite(trig_pin, LOW); //Make sure ultrasound is off
delayMicroseconds(2);
digitalWrite(trig_pin, HIGH); //Send ping
delayMicroseconds(10);  //Ping must remain high for 10ms to send a proper signal out.
digitalWrite(trig_pin, LOW);  //stop ping
travelTime= pulseIn(echo_pin, HIGH); // gives the time in micro seconds
dist_in_cms= 0.017*travelTime; // calculated using distance= speed * time
Serial.println(dist_in_cms);
return dist_in_cms;
}

int check_direction(){
  /*
Checks left and right for an obstacle otherwise does a 360 turn
  */
int distances[2]={0,0}; //0 index is for left and 1 for right
int turn_dir;        // turn_dir 1 is reverse, 0 left, 2 right
myServo.write(180); // turn left
delay(300);
distances[0]= get_distance();
myServo.write(0); // turn right
delay(600);
distances[1]= get_distance();
if (distances[0]<stop_distance && distances[1]<stop_distance){
  turn_dir=1;
}
else if(distances[0]<stop_distance && distances[1]>stop_distance){
  turn_dir=2;
}
else if(distances[0]>stop_distance && distances[1]<stop_distance){ // if both are clear turn left
  turn_dir=0;
}
else if(distances[0]>distances[1]){
  turn_dir=0;
}
return turn_dir;
}