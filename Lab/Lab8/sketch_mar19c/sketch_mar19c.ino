 void setup(){
  Serial.begin(9600);
  motor_setup(); 
 }
 
 void loop(){
  int cycle=analogRead(A0);
  
  if (cycle >511.5){
    
  motor (0,(cycle-511.5)/2);
   Serial.println(String("Cycle - ")+cycle);
  }
  else
  {
   motor (1,(511.5-cycle)/2);
    Serial.println(String("Cycle - ")+cycle);
  }



 }
 
const int m_en=5;
const int m_i1=6;
const int m_i2=7;

void motor_setup(){
 pinMode(m_en,OUTPUT);
 pinMode(m_i1,OUTPUT);
 pinMode(m_i2,OUTPUT);
 digitalWrite(m_en,LOW);
 
}
 
void motor(int dir, int cycle){
if(dir==0)
  {
  digitalWrite(m_i1,HIGH);
  digitalWrite(m_i2,LOW);
  }
else 
  {
  digitalWrite(m_i2,HIGH);
  digitalWrite(m_i1,LOW);
  }
 analogWrite(m_en,cycle);  
}
