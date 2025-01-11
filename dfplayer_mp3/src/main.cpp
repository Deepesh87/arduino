#include <Arduino.h>
#include <DFRobot_DF1201S.h>
#include <SoftwareSerial.h>


// Speakers must be connected to R+-or l+-. Code only works when uploaded rom Arduino IDe.
//more details on DF player here https://wiki.dfrobot.com/DFPlayer_PRO_SKU_DFR0768#:~:text=Default%20serial%20baud%20rate%3A%20115200
SoftwareSerial DF1201SSerial(2, 3);  //connect VIN to 5V, gnd to gnd and RX to 3  TX to 2
 
DFRobot_DF1201S DF1201S; // create an object
 
void setup(void) {
  Serial.begin(115200);
  DF1201SSerial.begin(115200);  // initialise the object

  //return error if object is not found
  while (!DF1201S.begin(DF1201SSerial)) {
    Serial.println("Init failed, please check the wire connection!");
    delay(1000);
  }

  DF1201S.setVol(20); //set volumne to 20, 0 to 30 available.
  Serial.print("VOL set is:");
  Serial.println(DF1201S.getVol());
  /*Enter music mode*/
  DF1201S.switchFunction(DF1201S.MUSIC);
  /*Wait for the end of the prompt tone */
  /*Set playback mode to "SINGLE"*/
  DF1201S.setPlayMode(DF1201S.SINGLE);
  Serial.print("PlayMode:");
  /*Get playback mode*/
  Serial.println(DF1201S.getPlayMode());
  Serial.print("The number of files available to play:");
  //The number of files available to play
  Serial.println(DF1201S.getTotalFile());
}
 
void loop() {
/*
i have saved 2 mp3 files one is dance_music.mp3 lasting around 90 seconds, another is GOT.mp3 lasting around 87 seconds
FileNum for GOT is 1 and for dance_music is 2. (filenum is based on the order of saving the file on the player)

*/
  DF1201S.playFileNum(2); // will play file num 2
  Serial.print("Name of file playing is:");
  //Get the name of the playing file
  Serial.println(DF1201S.getFileName());
  Serial.print("Total duration of this file is : ");
  Serial.println(DF1201S.getTotalTime()); // will give the total duration of the mp3 file in seconds
  delay(10000);
  DF1201S.playFileNum(1);
  Serial.print("Name of file playing is:");
  //Get the name of the playing file
  Serial.println(DF1201S.getFileName());
  Serial.print("Total duration of this file is : ");
  Serial.println(DF1201S.getTotalTime());

  delay(10000);
  Serial.println("moving to the next song now");  
  DF1201S.next();
  Serial.print("Name of file playing is:");
  //Get the name of the playing file
  Serial.println(DF1201S.getFileName());
  delay(10000);  
  Serial.println("The Loop ends here*******");
}


// DF1201S.setPrompt(false); // to stop the prompt music music 