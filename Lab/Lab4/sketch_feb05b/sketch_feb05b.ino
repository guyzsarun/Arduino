const int pushButton=8;

void setup(){
    Serial.begin(9600);
    pinMode(pushButton,INPUT_PULLUP);
}
int count=0;

void loop(){
  
    int buttonState=digitalRead(pushButton);
 
    if (buttonState==LOW)
        {
         while(digitalRead(8)!=HIGH)
            {
            }
          delay(1);
          
        count++;
        Serial.print("click");
        Serial.print(count);
        Serial.println("");
        }
        
}

