#include <Servo.h>
#include <EEPROM.h>

#define prev_add1 1   //rE
#define prev_add2 2   //rM
#define prev_add3 3   //rB
#define prev_add4 4   //lE
#define prev_add5 5   //lM
#define prev_add6 6   //lB

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

int ft,fn,fm,fl;
int St[25],Sn[25],Sm[25],Sl[25];

int t,n,m,l; 

void setup() {
  
  Serial.begin(9600);
  
  myservo_rE.attach(3); 
  myservo_rM.attach(5); 
  myservo_rB.attach(6);
  myservo_lE.attach(9);
  myservo_lM.attach(10);
  myservo_lB.attach(11);
  
// initial out position

myservo_rE.write(EEPROM.read(prev_add1)); 
myservo_rM.write(EEPROM.read(prev_add2)); 
myservo_rB.write(EEPROM.read(prev_add3));
myservo_lE.write(EEPROM.read(prev_add4));  
myservo_lM.write(EEPROM.read(prev_add5)); 
myservo_lB.write(EEPROM.read(prev_add6));
 
}

void loop() {
  
  // put your main code here, to run repeatedly:

int i=0;

for(i=0;i<25;i++)
{
  St[i]=analogRead(A1);
  Sl[i]=analogRead(A4);
  Sn[i]=analogRead(A2);
  Sm[i]=analogRead(A3);
  ft=ft+St[i];
  fn=fn+Sn[i];
  fm=fm+Sm[i]; 
  fl=fl+Sl[i];
  delay(1);
}

ft=ft/25;
fn=fn/25;
fm=fm/25;
fl=fl/25;
if (fn>720&&fm>750){
// out to in
//rb
while(pos_rB>60) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB-1;
delay(1);
}
//lb
while(pos_lB<30) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB+1;
delay(1);
}
//rm
while(pos_rM<70) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM+1;
delay(1);
}
//lm
while(pos_lM>75) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM-1;
delay(1);
}
//re
while(pos_rE>160) {
myservo_rE.write(pos_rE);
pos_rE=pos_rE-1;
delay(1);
}
//le
while(pos_lE>100) {
myservo_lE.write(pos_lE);
pos_lE=pos_lE-1;
delay(1);
}
}
if(fn<690&&fm<710){
//in to out 
while(pos_lE<110) {
myservo_lE.write(pos_lE);
pos_lE=pos_lE+1;
delay(1);
}
//re
while(pos_rE<180) {
myservo_rE.write(pos_rE);
pos_rE=pos_rE+1;
delay(1);
}
//lm
while(pos_lM<130) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM+1;
delay(1);
}
//rm
while(pos_rM>20) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM-1;
delay(1);
}
//lb
while(pos_lB>0) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB-1;
delay(1);
}
//rb
while(pos_rB<100) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB+1;
delay(1);
}
}
update_eeprom();

}

void update_eeprom(){
  
  EEPROM.write(prev_add1, pos_rE);
  EEPROM.write(prev_add2, pos_rM);
  EEPROM.write(prev_add3, pos_rB);
  EEPROM.write(prev_add4, pos_lE);
  EEPROM.write(prev_add5, pos_lM);
  EEPROM.write(prev_add6, pos_lB);

}
