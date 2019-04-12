  void setup(){
     Serial.begin(9600);
     extPortInit(); 
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
  
  void loop(){
      int value=analogRead(A0);
      int voltage=5.0*value/1023;
      Serial.print("The value is ");
      Serial.print(value);
      Serial.print(" - ");
      Serial.print(voltage);
      Serial.println(" volt(s).");   
      

     extPortWrite(dig[voltage]);

  }
