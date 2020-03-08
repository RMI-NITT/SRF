

int ft,fn,fm,fl;
int St[25],Sn[25],Sm[25],Sl[25];

int t,n,m,l; 

void setup() {
  
  Serial.begin(9600);
  
 
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


t=map(ft,400,1100,50,180);
l=map(fl,360,1000,0,180);

//Serial.println(n);
Serial.println(l);


//Serial.println("not wroking");



}
