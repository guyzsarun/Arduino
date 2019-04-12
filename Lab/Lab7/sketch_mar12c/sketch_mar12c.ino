void setup(){
  Serial.begin(9600);
  Serial.println("Adriono Lab 7 , Exercise 3 ");
}

char buffer[80];

void loop(){  
  while (!Serial.available())
    {}
   Serial.readBytes(buffer,80);
   String name=String(buffer);
   Serial.println(name);

   int last=0;
   int i=0;
   int count=0;
   
   String check;
   
   for(i=0;i<name.length();i++)
     {
       if ((name.charAt(i)>='A'&&name.charAt(i)<='Z')||(name.charAt(i)>='a'&&name.charAt(i)<='z'))
        {
         last++;
        }
     }
   

   Serial.print("There are ");
   Serial.print(last);
   Serial.print(" characters \n");

 
  
   for (i=0;i<name.length();i++)
   {    
    name.replace("  "," ");	
   }
  
   for (i=0;i<name.length();i++)
     {
      if (name.charAt(i)==' ')
       {
        count++;
       }
     }
   
   
   Serial.print("There are ");
   Serial.print(count+1);
   Serial.print(" words \n");
   
     

   memset(buffer, 0, sizeof(buffer));
   
   
   
  Serial.println(".");
}


