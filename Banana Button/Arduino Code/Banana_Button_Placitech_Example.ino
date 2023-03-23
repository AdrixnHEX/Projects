/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to use a banana as a button to turn on an LED! 
 *  In this example you will be reading the value of pin A4 and using
 *  it to determine if your finger is touching the banana. The principle
 *  being used in this project is Voltage Division, which says that
 *  input voltage gets distributed among the components of a circuit
 *  depending on their individual resistance. The higher the value of
 *  the resistor, the greater the voltage drop across it. As you might
 *  be guessing, the combined resistance of our bodies and the banana
 *  is what produces the slight voltage drop that we are reading on pin
 *  A4. Of course, this only happens once we close the circuit (touching
 *  the banana). Also, the value of the resistor shown in the circuit
 *  diagram is 1 MΩ.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

#define banana A4
#define led 2

int val;

void setup() {
  Serial.begin(9600);
  pinMode(banana, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}



void loop() {
  val = analogRead(banana);
/*Whenever we are not touching the banana
the value of pin 4 should be 1023 (5V)
*/
  while (val >= 1000){
    Serial.println(val);
    delay(10);
    val = analogRead(banana);
  }
  
  digitalWrite(led, HIGH);
/* Once we touch it, the value goes a bit down (<1000, <5V)
   due to the voltage drop. This value might be
   different for you since we are not using the
   same banana, so make sure to tweak the code if needed
*/
  while (val < 1000){
    Serial.println(val);
    delay(10);
    val = analogRead(banana);
  }
  
  digitalWrite(led, LOW);
}
