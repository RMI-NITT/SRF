int ft,fn,fm,fl;
int St[25],Sn[50],Sm[50],Sl[50];
int t,n,m,l; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int i;
for(i=0;i<25;i++)
{
  St[i]=analogRead(A1);
//  Sl[i]=analogRead(A4);
//  Sn[i]=analogRead(A2);
//  Sm[i]=analogRead(A3);

  delay(10);
  ft=ft+St[i];
//  fn=fn+Sn[i];
//  fm=fm+Sm[i]; 
//  fl=fl+Sl[i];
}
ft=ft/25;
//fn=fn/50;
//fm=fm/50;
//fl=fl/50;

Serial.println(ft);

}
