
  void setup(){
   Serial.begin(9600);
   pinMode(3,OUTPUT);
}

void loop(){
    
    int value=analogRead(A0);
    digitalWrite(3,HIGH);
    delay(value);
    digitalWrite(3,LOW);
    delay(value); 
  

    float voltage=5.0*value/1023;
    Serial.print("The value is ");
    Serial.print(value);
    Serial.print(" - ");
    Serial.print(voltage);
    Serial.println(" volt(s).");    
}
