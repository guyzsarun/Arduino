const int pushButton=8;

void setup(){
    Serial.begin(9600);
    pinMode(pushButton,INPUT_PULLUP);
    Serial.println("Exercise 4 : Number to 7-segment display");
    Serial.println("Please input a number.");
    extPortInit(); 
}
int readData=0;

const int max=11;
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
  {LOW,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH},          //9
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW,HIGH}     //-
};

void loop(){
 
    
    if (Serial.available()>0)
        {
         readData=Serial.read();
         Serial.print(">");
         Serial.write(readData);
         Serial.println("");             
        }
    
    if (readData<48)
        {
        extPortWrite(dig[10]);
        }
   if (readData>57)
       {
        extPortWrite(dig[10]); 
       }
        
  else
    {
     extPortWrite(dig[readData-48]); 
    }

}
