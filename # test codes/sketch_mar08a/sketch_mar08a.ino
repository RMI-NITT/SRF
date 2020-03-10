int ft,fn,fm,fl;
int St[50],Sn[50],Sm[50],Sl[50];
int t,n,m,l; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i;
for(i=0;i<50;i++)
{
  St[i]=analogRead(A1);
  Sl[i]=analogRead(A4);
  Sn[i]=analogRead(A2);
  Sm[i]=analogRead(A3);

  ft=ft+St[i];
  fn=fn+Sn[i];
  fm=fm+Sm[i]; 
  fl=fl+Sl[i];
}
ft=ft/50; //320 +-
fn=fn/50; //350 +-
fm=fm/50; //370 -600
fl=fl/50; //300 +-

Serial.println(ft);

}
