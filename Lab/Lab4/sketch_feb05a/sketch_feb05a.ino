const int pushButton=8;

void setup(){
    Serial.begin(9600);
    pinMode(pushButton,INPUT_PULLUP);
}

void loop(){
  
    int buttonState=digitalRead(pushButton);
    Serial.print("The logic is ..");
    if (buttonState==HIGH)
        {
        Serial.println("HIGH");
        }
     else
       {
        Serial.println("LOW"); 
       }
}
