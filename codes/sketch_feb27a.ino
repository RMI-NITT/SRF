#include <Servo.h>

Servo myservo1; 
Servo myservo2; 
Servo myservo3; // create servo object to control a servo
// twelve servo objects can be created on most boards

String pos;    // variable to store the servo position

void setup() {
  myservo1.attach(5); 
  myservo2.attach(6); 
  myservo3.attach(7); // attaches the servo on pin 9 to the servo object
}

void loop() {
  Serial.println(Serial.available());
  if (Serial.available()>0)
{ 
  pos=Serial.readStringUntil(' ');
  myservo1.write(pos.toInt());
  Serial.println(pos);
  pos=Serial.readStringUntil(' ');
  myservo1.write(pos.toInt());
  Serial.println(pos); 
  pos=Serial.readStringUntil(' ');
  myservo1.write(pos.toInt());
  Serial.println(pos);
}
}
