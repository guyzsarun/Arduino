void setup(){
   Serial.begin(9600); 
}

void loop(){
    if(Serial.available()>0)
      {
       int key=Serial.read();
       Serial.write(key);
       
       switch (key){
         
       case 'c':
         tone(3,262,1000);
         break;
       case 'd':
         tone(3,294,1000);
         break;
       case 'e':
         tone(3,330,1000);
         break;
       case 'f':
         tone(3,350,1000);
          break;
       case 'g':
         tone(3,392,1000);
         break;
       case 'a':
         tone(3,440,1000);
         break;
       case 'b':
         tone(3,494,1000);
         break;
         
       case 'C':
         tone(3,523,1000);
         break;
       case 'D':
         tone(3,587,1000);
         break;
          case 'E':
         tone(3,659,1000);
         break;
          case 'F':
         tone(3,698,1000);
         break;
          case 'G':
         tone(3,784,1000);
         break;
          case 'A':
         tone(3,880,1000);
         break;
          case 'B':
         tone(3,988,1000);
         break;
         
         default:
         Serial.println("\nWrong Note");
       
        
      }
      delay (1300);
      menu();
      }
}

void menu(){
  Serial.println("\nExercise 3\n Please enter note [c..d,C..A]");
  Serial.print(">");
}
