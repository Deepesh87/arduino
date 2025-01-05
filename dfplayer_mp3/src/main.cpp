#include <Arduino.h>
#include <DFRobot_DF1201S.h>
#include <SoftwareSerial.h>

SoftwareSerial mySoftwareSerial(2, 3); //RX  TX
DFRobot_DF1201S DF1201S;
void play_first();
void play_second();



void setup()
{
Serial.begin(115200);
mySoftwareSerial.begin(115200);
// DF1201S.begin(mySoftwareSerial, 0);
// while(!DF1201S.begin(mySoftwareSerial)){
//   Serial.println("Init failed, please check the wire connection!");
//   delay(1000);
// }
Serial.println("xxxxxxxxxxxxxxxx");
DF1201S.setVol(30);
Serial.print("VOL:");
Serial.println(DF1201S.getVol());


DF1201S.switchFunction(DF1201S.MUSIC);
delay(2000);

DF1201S.setPlayMode(DF1201S.SINGLE);
Serial.print("PlayMode:");
Serial.println(DF1201S.getPlayMode());
DF1201S.setPrompt(false);
}


void loop() {
Serial.println("==============================");
// play_first(); 
// Serial.println("abcdefghijklmnopqrstuvwxyz");
// play_second();
}

void play_first() {
  DF1201S.playFileNum(1);
  DF1201S.setPlayTime(20);
    Serial.print("Playing First Track... ");
    Serial.println(DF1201S.getFileName());
    Serial.println("Starts at 20 seconds in ");
    Serial.println("Plays for 20 seconds ");
    Serial.print("Track Length ");
    Serial.println(DF1201S.getTotalTime());
  delay(20000);
    Serial.println("End of play_first()  ");
    Serial.println(" ");    
}

void play_second() {
  DF1201S.playFileNum(02);
  DF1201S.setPlayTime(30);
    Serial.print("Playing Second Track... ");
    Serial.println(DF1201S.getFileName());
    Serial.println("Starting 30 seconds in ");
  DF1201S.setVol(5);
    Serial.print("VOL:");
    Serial.println(DF1201S.getVol());
    Serial.print("Track Length ");
    Serial.println(DF1201S.getTotalTime());
    Serial.println("Plays for 10 seconds ");
    Serial.println(" ");
  delay(10000);
    Serial.println("Now skips to 40 seconds in ");
  DF1201S.fastForward(/*FF = */40);
    Serial.println("Plays for 10 seconds ");
  delay(10000);
    Serial.println(" ");
  DF1201S.setPlayTime(30);
    Serial.println("Skips to 30 seconds in ");
    Serial.println("For 5 seconds ");
    Serial.println("End of Instructions from play_second() ");
  delay(5000);
    Serial.println(" ");
}