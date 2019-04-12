const int pushButton=8;

void setup(){
    Serial.begin(9600);
    pinMode(pushButton,INPUT_PULLUP);
    extPortInit(); 
     randomSeed(analogRead(0));
    
    menu();
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

int std1[max][8]={
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

int std2[max][8]={
  {LOW,HIGH,LOW,LOW,LOW,LOW,LOW,HIGH},        //6
  {LOW,LOW,LOW,LOW,LOW,LOW,HIGH,HIGH},      //0
  {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH},        //3
{HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},      //1
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH},      //8
  {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH},        //3
    {LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH},      //8
   {HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH},        //4
  {LOW,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH},      //2
 {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,LOW}    //1
};

int dice=random(1,7);

void loop(){
 
    
    if (Serial.available()>0)
        {
         readData=Serial.read();
       
        switch (readData)
          {
            case 49:
               Serial.println("Sarun Nuntaviriyakul  ID : 6031851521"); 
               for (int i=0;i<max;i++)
                     {
                      extPortWrite(std1[i]);
                     delay(1000); 
                     }    
              
          break;
           
           case 50:
                Serial.println("Rhach Roongnirandon ID : 6031838421"); 
                for (int i=0;i<max;i++)
                     {
                     extPortWrite(std2[i]);
                     delay(1000); 
                     }  
          
          break;
         
          case  53:
              dice=random(1,7);
              extPortWrite(dig[dice]);
             
         
         break;
        
        default :
        extPortWrite(dig[10]);      
          }
        }
}

void menu(){
   Serial.println("Exercise 5 : Multi-functions program"); 
   Serial.println("\nPlease select your function.");
   Serial.println(" 1- First member");
   Serial.println(" 2- Second member");
   Serial.println(" 5- Digital Dice");
   Serial.println("");   
}


