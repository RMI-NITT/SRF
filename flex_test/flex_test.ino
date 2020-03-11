int ft,fn,fm,fl;
int St[50],Sn[50],Sm[50],Sl[50];
int t,n,m,l; 

void setup() {
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
//Serial.println(fl);//700 700 800 700
//1 – clos.e
if((fl < 700) && (fm < 800) && (fn > 700) && (ft < 700)){Serial.println("clos.e");}
//2 – ope.n 
if((fl < 700) && (fm > 800) && (fn < 700) && (ft < 700)){Serial.println("ope.n");}
//3 – hold up
if((fl < 700) && (fm > 800) && (fn > 700) && (ft < 700)){Serial.println("hold up");}
//5 – one up and down hold 
if((fl < 700) && (fm > 800) && (fn > 700) && (ft > 700)){Serial.println("one up and down hold");}
//6 – normal 
if((fl < 700) && (fm < 800) && (fn < 700) && (ft < 700)){Serial.println("normal");  }
delay(100);
}
