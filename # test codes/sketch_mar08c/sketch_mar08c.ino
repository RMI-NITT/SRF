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
void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
  // put your main code here, to run repeatedly:
pos_rE=180;
pos_rM=0;
pos_rB=180;
pos_lE=180;
pos_lM=180;
pos_lB=0;
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
