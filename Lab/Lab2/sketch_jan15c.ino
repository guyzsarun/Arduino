int state=0;

void setup(){
   pinMode(8,INPUT_PULLUP);
   pinMode(4,OUTPUT);
   
   digitalWrite(4,HIGH);
  }
  
void loop(){
  
  
  if(digitalRead(8)==LOW)
    {
     while(digitalRead(8)!=HIGH)
        {
        }
      delay(1);
     
    
    if (state==0)
        {
        digitalWrite(4,LOW);
        state=1;
        }
     else if (state==1)
       {
        digitalWrite(4,HIGH);
        state=0;
        }
      } 
  }
