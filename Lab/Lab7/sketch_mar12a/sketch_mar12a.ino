void setup(){
  Serial.begin(9600);
  Serial.println("Adriono Lab 7 , Exercise 1 ");
}

char buffer[80];

void loop(){
  Serial.print("Please enter your name (with Mr. or Ms.)\n>");
  while (!Serial.available())
    {}
   Serial.readBytes(buffer,80);
   String name=String(buffer);
   Serial.println(name);
   
   int pos;
   if ((pos=name.indexOf("Mr."))!=-1) {
     Serial.println("Hello mister! "+name.substring(pos+3));
   }
   else if ((pos=name.indexOf("Ms."))!=-1) {
     Serial.println("Hello miss! "+name.substring(pos+3));
   }
   else {
      Serial.println("Hello there! " +name);
   }
  Serial.println(".");
  memset(buffer, 0, sizeof(buffer));
}
