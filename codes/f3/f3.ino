int S1[25],S2[25];
int f1,f2;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=0;
for(i=0;i<25;i++)
{
  S1[i]=analogRead(A1);
  delay(10);
  f1=f1+S1[i];
  }
for(i=0;i<25;i++)
{
  S2[i]=analogRead(A2);
  delay(10);
  f2=f2+S2[i];
  }

f1=f1/25;
f2=f2/25;

if (f1>990&&f2>660)
Serial.println("f1,-f2");
if (f1<990&&f2<660)
Serial.println("f1,+f2");
else
Serial.println("not wroking");

}
