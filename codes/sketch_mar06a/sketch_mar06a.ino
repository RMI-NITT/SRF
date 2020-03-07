
#include <Servo.h>

Servo myservo_rE;
Servo myservo_rM;
Servo myservo_rB;
Servo myservo_lE;
Servo myservo_lM;
Servo myservo_lB;

int pos_rE= 180;
int pos_rM= 20;
int pos_rB= 100;
int pos_lE= 110;
int pos_lM= 130;
int pos_lB= 0;   

void setup() {
  
  myservo_rE.attach(3); 
  myservo_rM.attach(5); 
  myservo_rB.attach(6);
  myservo_lE.attach(9);
  myservo_lM.attach(10);
  myservo_lB.attach(11);
  
// initial out position
myservo_rE.write(180); 
myservo_rM.write(20); 
myservo_rB.write(100);
myservo_lE.write(110);  
myservo_lM.write(130); 
myservo_lB.write(0);
 
}

void loop() {
// out to in

//rb
while(pos_rB>60) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB-1;
delay(10);
}
//lb
while(pos_lB<30) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB+1;
delay(10);
}
//rm
while(pos_rM<70) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM+1;
delay(10);
}
//lm
while(pos_lM>75) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM-1;
delay(10);
}
//re
while(pos_rE>160) {
myservo_rE.write(pos_rE);
pos_rE=pos_rE-1;
delay(10);
}
//le
while(pos_lE>100) {
myservo_lE.write(pos_lE);
pos_lE=pos_lE-1;
delay(10);
}

//in to out 

//le
while(pos_lE<110) {
myservo_lE.write(pos_lE);
pos_lE=pos_lE+1;
delay(10);
}
//re
while(pos_rE<180) {
myservo_rE.write(pos_rE);
pos_rE=pos_rE+1;
delay(10);
}
//lm
while(pos_lM<130) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM+1;
delay(10);
}
//rm
while(pos_rM>20) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM-1;
delay(10);
}
//lb
while(pos_lB>0) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB-1;
delay(10);
}
//rb
while(pos_rB<100) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB+1;
delay(10);
}

}
