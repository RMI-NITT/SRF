
#include <Servo.h>

Servo myservo_rE;
Servo myservo_rM;
Servo myservo_rB;
Servo myservo_lE;
Servo myservo_lM;
Servo myservo_lB;

int pos =0;
int pos_rE= 180;
int pos_rM= 40;
int pos_rB= 70;
int pos_lE= 110;
int pos_lM= 120;
int pos_lB= 20;   

void setup() {
  
  myservo_rE.attach(3); 
  myservo_rM.attach(5); 
  myservo_rB.attach(6);
  myservo_lE.attach(9);
  myservo_lM.attach(10);
  myservo_lB.attach(11);

myservo_rE.write(180); 
myservo_rM.write(40); 
myservo_rB.write(70); 
myservo_lE.write(110); 
myservo_lM.write(120); 
myservo_lB.write(20); 

}

void loop() {

 // out to in
// angle D - rE,rB,lE,lM
for (pos = 50; pos >= 0; pos -= 1) {
// angle D - rE,rB,lE,lM 
    myservo_rE.write(pos_rE);
    myservo_rB.write(pos_rB);
    myservo_lE.write(pos_lE);
    myservo_lM.write(pos_lM); 

    pos_rE = pos_rE - pos;
    pos_rB = pos_rB - pos;
    pos_lE = pos_lE - pos;
    pos_lM = pos_lM - pos; 

// angle I - rM,lB
    myservo_rM.write(pos_rM);
    myservo_lB.write(pos_lB); 

    pos_rM = pos_rM + pos;
    pos_lB = pos_lB + pos;

    delay(150);                                             
  }
  
  // in to out 
for (pos = 0; pos <= 50; pos += 1) { 
// angle I - rE,rB,lE,lM
    myservo_rE.write(pos_rE);
    myservo_rB.write(pos_rB);
    myservo_lE.write(pos_lE);
    myservo_lM.write(pos_lM); 

    pos_rE = pos_rE + pos;
    pos_rB = pos_rB + pos;
    pos_lE = pos_lE + pos;
    pos_lM = pos_lM + pos;
    
// angle D - rM,lB
    myservo_rM.write(pos_rM);
    myservo_lB.write(pos_lB); 

    pos_rM = pos_rM - pos;
    pos_lB = pos_lB - pos;

    delay(150);    
  }

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
