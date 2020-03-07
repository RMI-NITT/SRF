#include <Servo.h>
#include <EEPROM.h>

#define prev_add1 1  //rE
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
int st[50],sn[50],sm[50],sl[50];

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

for(i=0;i<50;i++)
{
  ft[i]=analogRead(A1);
  delay(10);
  ft=ft+st[i];
  }
for(i=0;i<50;i++)
{
  Sn[i]=analogRead(A2);
  delay(10);
  fn=fn+Sn[i];
  }
for(i=0;i<50;i++)
{
  fm[i]=analogRead(A3);
  delay(10);
  fm=fm+sm[i];
  }
for(i=0;i<50;i++)
{
  Sl[i]=analogRead(A4);
  delay(10);
  fl=fl+Sl[i];
  }

ft=ft/50;
fn=fn/50;
fm=fm/50;
fl=fl/50;



pos_rM = map()

Serial.println("not working");

}
