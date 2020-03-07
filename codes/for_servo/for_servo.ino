#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo5;
Servo myservo4;

int pos = 0;
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
  //                           SERVO      OUT         IN
myservo2.write(90);            //RB D IN  90          50(60)
myservo3.write(30);            //RM I IN  30          70(60)
myservo1.write(180);           //RE D IN  180         150(180)

myservo5.write(20);            //LB I IN  20           150
myservo4.write(90);           //LE D IN  150         60(90) 

for (pos2 = 90; pos2 >= 60; pos2 -= 1) { 
    myservo2.write(pos2);              
    delay(15);                       
  }
for (pos5 = 20; pos5 <= 150; pos5 += 1) { 
    // in steps of 1 degree
    myservo5.write(pos5);              
    delay(15);                      
  }
for (pos3 = 30; pos3 <= 90; pos3 += 1) { 
    // in steps of 1 degree
    myservo3.write(pos3);              
    delay(15);                      
  }
for (pos4 = 150; pos4 >= 40; pos4 -= 1) { 
    myservo4.write(pos4);              
    delay(15);                       
  }
  
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
