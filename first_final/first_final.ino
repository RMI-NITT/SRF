#include <Servo.h>
#include <EEPROM.h>

#define prev_add1 1   //rE
#define prev_add2 2   //rM
#define prev_add3 3   //rB
#define prev_add4 4   //lE
#define prev_add5 5   //lM
#define prev_add6 6   //lB

int pos_rE= 180;
int pos_rM= 20;
int pos_rB= 100;
int pos_lE= 110;
int pos_lM= 130;
int pos_lB= 0;  

Servo myservo_rE;
Servo myservo_rM;
Servo myservo_rB;
Servo myservo_lE;
Servo myservo_lM;
Servo myservo_lB;

int ft,fn,fm,fl;
int St[50],Sn[50],Sm[50],Sl[50];
int t,n,m,l; 

void setup() {
  
  myservo_rE.attach(3); 
  myservo_rM.attach(5); 
  myservo_rB.attach(6);
  myservo_lE.attach(9);
  myservo_lM.attach(10);
  myservo_lB.attach(11);
  
myservo_rE.write(EEPROM.read(prev_add1)); 
myservo_rM.write(EEPROM.read(prev_add2)); 
myservo_rB.write(EEPROM.read(prev_add3));
myservo_lE.write(EEPROM.read(prev_add4));  
myservo_lM.write(EEPROM.read(prev_add5)); 
myservo_lB.write(EEPROM.read(prev_add6));

Serial.begin(9600);

pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);

}

void loop() {
  
int i;

for(i=0;i<50;i++){
  
  St[i]=analogRead(A1);
  Sn[i]=analogRead(A2);
  Sm[i]=analogRead(A3);
  Sl[i]=analogRead(A4);

  ft=(ft+St[i])/2;
  fn=(fn+Sn[i])/2;
  fm=(fm+Sm[i])/2; 
  fl=(fl+Sl[i])/2;
  
}

//1 – clos.e
if((fl < 700) && (fm < 800) && (fn > 700) && (ft < 700)){Serial.println("clos.e");
pos_rE=180;
pos_rM=70;
pos_rB=50;
pos_lE=100;
pos_lM=80;
pos_lB=130;}
//2 – ope.n 
if((fl < 700) && (fm > 800) && (fn < 700) && (ft < 700)){Serial.println("ope.n");
pos_rE=180;
pos_rM=0;
pos_rB=110;
pos_lE=120;
pos_lM=150;
pos_lB=0;}
//3 – hold up
if((fl < 700) && (fm > 800) && (fn > 700) && (ft < 700)){Serial.println("hold up");
pos_rE=150;
pos_rM=80;
pos_rB=180;
pos_lE=70;
pos_lM=80;
pos_lB=40;}
//5 – one up and down hold 
if((fl < 700) && (fm > 800) && (fn > 700) && (ft > 700)){Serial.println("one up and down hold");
pos_rE=180;
pos_rM=20;
pos_rB=180;
pos_lE=90;
pos_lM=80;
pos_lB=130;}
//6 – normal 
if((fl < 700) && (fm < 800) && (fn < 700) && (ft < 700)){Serial.println("normal");  
pos_rE=180;
pos_rM=40;
pos_rB=70;
pos_lE=110;
pos_lM=120;
pos_lB=20;}

delay(100);

myservo_rE.write(pos_rE); 
myservo_rM.write(pos_rM); 
myservo_rB.write(pos_rB);
myservo_lE.write(pos_lE);  
myservo_lM.write(pos_lM); 
myservo_lB.write(pos_lB);

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
