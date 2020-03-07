
#include <Servo.h>

Servo myservo_rE;
Servo myservo_rM;
Servo myservo_rB;
Servo myservo_lE;
Servo myservo_lM;
Servo myservo_lB;

int pos_rE= 0;
int pos_rM= 0;
int pos_rB= 0;
int pos_lE= 0;
int pos_lM= 0;
int pos_lB= 0;   

void setup() {
  
  myservo_rE.attach(3); 
  myservo_rM.attach(5); 
  myservo_rB.attach(6);
  myservo_lE.attach(9);
  myservo_lM.attach(10);
  myservo_lB.attach(11);
 
}

void loop() {
myservo_rE.write(140); 
myservo_rM.write(75); 
myservo_rB.write(180);
myservo_lE.write(65);  
myservo_lM.write(85); 
myservo_lB.write(45); 
  
}

/*
Right 
In out rgi nro
E - 70 180 120 180
M - 130 0 80 40
B - 0 180(special position tab hold points up) 70.
Left 
E - 0(points up) 180 (special position points down) 90 110
M - 10 180 60 120
B - 180 0 20
*/
