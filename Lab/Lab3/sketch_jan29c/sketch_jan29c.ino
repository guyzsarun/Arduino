void setup(){
   extPortInit(); 
   pinMode(0,INPUT_PULLUP);
   pinMode(1,INPUT_PULLUP);
}

const int max=10;
int dig[max][8]={
  {LOW,LOW,LOW,LOW,LOW,LOW,HIGH,HIGH},          //0
  {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},      //1
  {LOW,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH},         //2
  {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH},         //3
  {HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH},        //4
   {LOW,HIGH,LOW,LOW,HIGH,LOW,LOW,HIGH},        //5
  {LOW,HIGH,LOW,LOW,LOW,LOW,LOW,HIGH},          //6
  {LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},       //7
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH},           //8
  {LOW,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH}           //9
};



 int i=0;


void loop(){
  
  if(digitalRead(0)==LOW)
    {
     while(digitalRead(0)!=HIGH)
        {
        }
      delay(1);
      if(i<9)
        {
         i++;
        }
     }
   if(digitalRead(1)==LOW)
      {
       while(digitalRead(1)!=HIGH)
          {
          }
        delay(1);
        if(i>0 )
          {
          i--;
          }
      }
    extPortWrite(dig[i]);
    } 
  
