void extPortInit(){
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,0);
  digitalWrite(7,0);
}

void extPortWrite(int *data){
  for (int i=0;i<8;i++) {
    digitalWrite(4,data[7-i]);
    digitalWrite(8,HIGH);
    delay(10);
    digitalWrite(8,LOW);
  }
   digitalWrite(7,HIGH);
   delay(10);
   digitalWrite(7,LOW); 
  
  
  
}
