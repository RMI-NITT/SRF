int sensorValue1 =0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue1 = analogRead(A0); //990 660 770 960 
 

  Serial.println(sensorValue1);
 
}
