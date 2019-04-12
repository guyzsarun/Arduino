  void setup(){
     Serial.begin(9600);
  }
  
 

  void loop(){
      int value=analogRead(A0);
      float voltage=5.0*value/1023;
      Serial.print("The value is ");
      Serial.print(value);
      Serial.print(" - ");
      Serial.print(voltage);
      Serial.println(" volt(s).");   
    
  }
