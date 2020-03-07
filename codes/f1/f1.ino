int sensorValue1 =0;
int sensorValue2 =0;
int sensorValue3 =0;
int sensorValue4 =0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue1 = analogRead(A0); //
sensorValue2 = analogRead(A1); //
  sensorValue3 = analogRead(A2); // 
sensorValue4 = analogRead(A3); //
  // print out the value you read:
  Serial.println(sensorValue1);
  Serial.print(",1,"); 
  delay(10);     
  Serial.println(sensorValue2);
  Serial.print(",2,"); 
  delay(10); 
  Serial.println(sensorValue3);
  Serial.print(",3,");  
  delay(10); 
  Serial.println(sensorValue4);
  Serial.print(","); 
  delay(10); 
}
