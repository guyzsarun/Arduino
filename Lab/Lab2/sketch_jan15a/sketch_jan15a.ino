

void setup(){
   pinMode(8,INPUT_PULLUP);
   pinMode(4,OUTPUT);
  
  }
  
void loop(){
  if(digitalRead(8)==HIGH)
    {
     digitalWrite(4,HIGH);
   }
  else
    {
     digitalWrite(4,LOW);
     }
}
