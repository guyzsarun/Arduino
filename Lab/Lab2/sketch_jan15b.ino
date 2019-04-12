
void setup(){
   for(int i=0;i<4;i++)
     {
     pinMode(8+i,INPUT_PULLUP);
     pinMode(4+i,OUTPUT);
     }
  }
  
void loop(){
    
 for(int i=0;i<4;i++)
   {
    if(digitalRead(8+i)==HIGH)
    {
    digitalWrite(4+i,HIGH);    
    }
    else
    {
     digitalWrite(4+i,LOW); 
    }
  }
}
