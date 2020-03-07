#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo5;
Servo myservo4;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;    
int pos4 = 0;    
int pos5 = 0;    

void setup() {
  
  myservo1.attach(9); 
  myservo2.attach(10); 
  myservo3.attach(11);
  myservo5.attach(3);
  myservo4.attach(6);
 
}

void loop() {
  //                            SERVO      OUT         IN
  
myservo1.write(180);           //RE D IN  180         150(180)
myservo3.write(80);            //RM I IN  30          70(60)
myservo2.write(60);            //RB D IN  90          50(60)

myservo4.write(90);            //LE D IN  150         60(90) 
myservo5.write(160);           //LB I IN  20           150


  
  /*
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  */
}
