
int ft,fn,fm,fl;
int t,n,m,l;
int St[50],Sn[50],Sl[50],Sm[50];
 

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
  ft=ft+St[i];
  fn=fn+Sn[i];
  fm=fm+Sm[i]; 
  fl=fl+Sl[i];
  delay(10);
}
t=ft/50;
n=fn/50;
m=fm/50;
l=fl/50;

//1 – clos.e
if ((l < 300) && (m < 370) && (n > 350) && (t < 320)){

Serial.println("clos.e");
}
//2 – ope.n 
if((l < 300) && (m > 370) && (n < 350) && (t < 320)){

Serial.println("ope.n");
}
//3 – hold up
if((l < 300) && (m > 370) && (n > 350) && (t < 320)){

Serial.println("hold up");

}
//5 – one up and down hold 
if((l < 300) && (m > 370) && (n > 350) && (t > 320)){

Serial.println("one up and down hold");
}
//6 – normal 
if((l < 300) && (m < 370) && (n < 350) && (t < 320)){

Serial.println("normal");  
}

delay(100);
}
