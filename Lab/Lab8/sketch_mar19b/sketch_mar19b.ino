 void setup(){
  Serial.begin(9600);
  motor_setup(); 
 }
 // clockwise =0
 void loop(){
  int cycle=1;
  
  cycle=255;
 motor (0,cycle);
 delay(5000);
 Serial.println(String("Cycle - ")+cycle);
 
 
 cycle=1;
 motor(1,cycle);
 delay(2000);
 Serial.println(String("Cycle - ")+cycle);
 
  cycle=255;
 motor (1,cycle);
 delay(3000);
 Serial.println(String("Cycle - ")+cycle);
 
 cycle=1;
 motor(1,cycle);
 delay(10000);
 Serial.println(String("Cycle - ")+cycle);

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
