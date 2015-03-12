
// Author: AndreasVan 2014-12-10
// This code is designed for Nano V.3 by AndreasVan
// this code is public domain, enjoy!

#include <Servo.h>


Servo ver; 
Servo hor;
boolean replay = true;

unsigned long time_since_last_reset = 0;

void setup() { 


  ver.attach(2);
  hor.attach(3); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void migrate(Servo &myServo, int newPos) {
  int wait=random(30,60); //random (40,60) (10,30)
  int pos = myServo.read(); //Read servo position
  if (pos < newPos) { 
    for (int i=pos; i < newPos; i++) {
      myServo.write(i);
      delay(wait); 
    }
  } else { 
    for (int i=pos; i > newPos; i--) { 
      myServo.write(i);
      delay(wait);
    }
  }
}
      
void randomPosition() {
  int rand=random(20,100); //Horzontal range 80 deg 
  migrate(hor, rand);
  
  rand=random(85,110); //Vertical range around 25 deg
  migrate(ver, rand);
}
   
void loop() { 
    digitalWrite(4, HIGH);   // turn the Laser on
    digitalWrite(5, HIGH);   // turn 5min led on 
    digitalWrite(6, HIGH);   // turn 4min led on
    digitalWrite(7, HIGH);   // turn 3min led on
    digitalWrite(8, HIGH);   // turn 2min led on 
    digitalWrite(9, HIGH);   // turn 1min led on 
    digitalWrite(10, HIGH);   // turn power on 
    digitalWrite(13, HIGH);  // turn onboard led on 

if(millis() >= 60000) // 5min
{
 digitalWrite(5, LOW);   // turn 5min led off
{
}}
if(millis() >= 120000) // 4min
{
 digitalWrite(6, LOW);   // turn 4min led off
{
}}
if(millis() >= 180000) // 3min
{
 digitalWrite(7, LOW);   // turn 3min led off
{
}}
if(millis() >= 240000) // 2min
{
 digitalWrite(8, LOW);   // turn 2min led off
{
}}
if(millis() >= 300000) // 1min
{
 digitalWrite(9, LOW);   // turn 2min led off
{
}}
 
  randomPosition();
  delay(1500);
 
  digitalWrite(4, LOW);   // turn the Laser off
  digitalWrite(13, LOW);   // turn onboard led off
  
 ver.write(120);
 hor.write(71);
 
 delay(1000);
  digitalWrite(10, LOW);   // turn power off

if(millis() >= 360000) // 360.000 mili = 6 minutes
{
while(1)
{
}
}
}



