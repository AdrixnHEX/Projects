/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to program a circuit for pranking your friends!
 *  Imagine you want to scare your roommate whenever they turn on the
 *  light in a room. To do this, you'll use a photoresistor and a 4.7 KΩ
 *  resistor in series to get the reading of pin A3. If the microcontroller
 *  detects that the light is on, it will play a sound using the DFPlayerMini
 *  MP3 module. So, you'll get an audio cue whenever your friend
 *  flips the switch!
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have these libraries installed
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini mp3module;

#define read_pin A3
const int threshold = 700;
int volt;


void setup() {
  Serial.begin(9600);
  pinMode(read_pin, INPUT);
  mySoftwareSerial.begin(9600);
  
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");
  
  mp3module.setTimeOut(500); // Set serial communictaion time out to 500 ms
  mp3module.volume(28);  //Set volume value (0-30).
  mp3module.EQ(DFPLAYER_EQ_NORMAL); // Set equalization to normal
  mp3module.outputDevice(DFPLAYER_DEVICE_SD); // Read music from MicroSD card
  delay(1000);
}



void loop() {
  volt = analogRead(read_pin);
  Serial.println();
  
  while (volt > threshold){
    delay(10);
    volt = analogRead(read_pin);
    Serial.println(volt);
  }

  Serial.println();
  Serial.println("Light ON. Playing prank sound");
  mp3module.play(1);
  delay(1000);

  while (volt <= threshold){
    delay(10);
    volt = analogRead(read_pin);
    Serial.println(volt);
  }

  Serial.println();
  Serial.println("Light OFF. Stopping prank sound");
  Serial.println();
  mp3module.stop();
  delay(1000);
}
