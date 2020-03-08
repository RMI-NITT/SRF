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

  delay(10);
  ft=ft+St[i];
  fn=fn+Sn[i];
  fm=fm+Sm[i]; 
  fl=fl+Sl[i];
}

ft=ft/25;
fn=fn/25;
fm=fm/25;
fl=fl/25;

Serial.println(fn);
Serial.println(fm);

n=map(fn,600,800,40,130);
m=map(fm,590,820,10,120);
t=map(ft,400,1100,50,180);
l=map(fl,360,1000,0,180);

Serial.println(n);
Serial.println(m);

if (fn>pos_rM)
{
//rm
while(pos_rM<fn) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM+1;
delay(10);
}
}
else
{
//rm
while(pos_rM>fn) {
myservo_rM.write(pos_rM);
pos_rM=pos_rM-1;
delay(10);  
}
}
if (fm<pos_lM)
{
//lm
while(pos_lM>fm) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM-1;
delay(10);
}
}
else 
{
//lm
while(pos_lM<fm) {
myservo_lM.write(pos_lM);
pos_lM=pos_lM+1;
delay(10);
}  
if (ft<pos_rB)
{
//rb
while(pos_rB>ft) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB-1;
delay(10);
}
else
{
//rb
while(pos_rB<ft) {
myservo_rB.write(pos_rB);
pos_rB=pos_rB+1;
delay(10);
}
}
if (pos_lB>fl)
{
//lb
while(pos_lB>fl) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB-1;
delay(10);
}
}
else
{
//lb
while(pos_lB<fl) {
myservo_lB.write(pos_lB);
pos_lB=pos_lB+1;
delay(10);
}
}
}

//Serial.println("not wroking");

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
