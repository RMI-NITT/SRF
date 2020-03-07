/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1; 
//Servo myservo2;
//Servo myservo3;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(5);
  /*
  myservo2.attach(6,500,1500);
  myservo3.attach(7,500,1500);
  */
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}

void loop() {
if (Serial.available()>10)
{ pos=Serial.parseInt();
  myservo1.write(pos);
  Serial.println(pos);
}

//myservo1.write(2000);
  /*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  */
}
