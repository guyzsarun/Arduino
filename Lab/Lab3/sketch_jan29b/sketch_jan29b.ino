void setup(){
   extPortInit(); 
}

const int max=10;
int dig[max][8]={
  {LOW,HIGH,LOW,LOW,LOW,LOW,LOW,HIGH},        //6
  {LOW,LOW,LOW,LOW,LOW,LOW,HIGH,HIGH},      //0
  {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH},        //3
{HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},      //1
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH},      //8
  {LOW,HIGH,LOW,LOW,HIGH,LOW,LOW,HIGH},      //5
  {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},      //1
   {LOW,HIGH,LOW,LOW,HIGH,LOW,LOW,HIGH},      //5
  {LOW,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH},      //2
 {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,LOW}    //1
};



void loop(){
 for (int i=0;i<max;i++)
   {
    extPortWrite(dig[i]);
   delay(1000); 
   }
 }
