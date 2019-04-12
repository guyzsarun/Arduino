void setup(){
   extPortInit(); 
}

void loop(){
 int dig[8]={LOW,LOW,LOW,LOW,LOW,LOW,HIGH,LOW};
extPortWrite(dig); 
 }
