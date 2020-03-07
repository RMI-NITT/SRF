#include<TimerOne.h>
int t,s=9;
float angle,pw;
void setup() {
  // put your setup code here, to run once:
 Timer1.initialize(20000); //Initialize Timer1 and set period as 20msecond
 Timer1.pwm(9,51);    //Initialize PWM in pin 9, set 50% dutyCycle
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("enter the angle");
  while(Serial.available()==0);
  angle=Serial.parseFloat();
  Serial.print(angle);
  pw=map(angle,0,180,3,15);
  pw=pw*1023/100;
  Timer1.setPwmDuty(s,pw);
  delay(100);
  }
