/*WARNING: THE ALARM LIKES TO TRIGGER AT RANDOM TIMES IF YOU SLAM THE DOOR.
 * 
 * 
 * Writen by Quinten Oortgijsen
 * Alarm that goes of if someone forgets to close the door
 * 
 * Installed by: Quinten and Maki
 * 
 * Pinout:
 * 
 * Piezo speaker
 * + -> pin 12
 * - -> gnd
 * 
 * Readswitch
 * + -> 5v
 * - -> gnd
 * Data -> pin 4
 */

int opentime;

void setup() {
pinMode(12, OUTPUT);
pinMode(4,INPUT_PULLUP);
int opentime;
Serial.begin(9600);
}

void loop() {
  int dooropen = digitalRead(4);
if (dooropen == 1) { //Check if door is open
opentime += 1;
Serial.println(opentime);
}


if (dooropen == 0){ //Check if door isn't open and reset the timer
opentime = 0;
}


if (opentime > 1500){ //Set off the alarm if the door is open for too long
tone(12, 2000);
delay(500);
noTone(12);
delay(500);
}
}

