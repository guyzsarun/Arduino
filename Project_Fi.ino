#include <Keypad.h>
#include <sevenSegmentDisplay.h>

#define segA 31
#define segB 32
#define segC 35
#define segD 36
#define segE 39
#define segF 40
#define segG 43

void(* resetFunc) (void) = 0; //declare reset function @ address 0

sevenSegmentDisplay ssd(COMMON_CATHODE, segA,segB,segC,segD,segE,segF,segG,A0);

#define numA 21
#define numB 19
#define numC 17
#define numD 15
#define numE 0
#define numF 2
#define numG 4


const byte ROWS = 4; 
const byte COLS = 3;

char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {numG,numF,numE,numD};
byte colPins[COLS] = {numC, numB, numA};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int ran[100];
int endGame=0;
int count=0;
int a=0;
int k=0;

String num;

int add=0;
long ans=0;
char key;
char plus;

int check=0;

#define led 13

void setup() {
pinMode(led,OUTPUT);

randomSeed(analogRead(0));
Serial.begin(9600);
Serial.print("\n********************************************************************\n");
Serial.write("\t\t\tWelcome to Memory Game\n");
Serial.print("\t Press * for Memory Game \t Press # for Addition Game\n");
Serial.print("********************************************************************\n\n");

while (1)
    {
    char key = keypad.getKey();
    while(!key)
        {
        key = keypad.getKey();
        }
    
    
    if (key=='*')
        {
        Serial.print("\t\t\t\tMemory Game\n");
        while(1)
            {
            ran[k]=random(0,10);
            delay(200);
            showNum(ran[k]);
            
            if(checkEnd(k)!=0)
                {
                ledOn(1);
                ssd.set('E');
                delay(1200);
                ssd.set('n');
                delay(1200);
                ssd.set('d');
                delay(1200);
                ssd.off();
                break;
                }
            ledOn(0);
            endGame++;
            k++;
            
            Serial.print("Score : ");
            Serial.println(endGame);
            }
        
        Serial.print("\n********************************************************************\n");
        Serial.println("\t\t\t\tGAME OVER!\n");
        Serial.print("Your Score is ");
        Serial.print(endGame);
        
        delay(1000);
        resetFunc(); //call reset
        
        
        break; 
        }   
    else if (key=='#')
      {
      Serial.print("\t\t\t\tAddition Game\n");
      
      
      while(1)
      { 
      ran[k]=random(0,10);
      delay(200);
      showNum(ran[k]);
      
      add=add+ran[k];
      ans=0;
      while(1)
            {
            plus=keypad.getKey();
            
            switch(plus)
                {
                case '0' ... '9':
                ans=ans*10 + (plus-'0');
                break;
                }
            if(plus=='#')
                  {
                  break;
                  }
               }
              if(add!=ans)
                  {
                  break;
                  }
              
              endGame++;
              k++;
              ledOn(0);
              Serial.print("Score : ");
              Serial.println(endGame);
              
              
              }
        
        
        ledOn(1);
        
        Serial.print("\n********************************************************************\n");
        Serial.println("\t\t\t\tGAME OVER!\n");
        Serial.print("Your Score is ");
        Serial.print(endGame);
        
        
        ssd.set('E');
        delay(1200);
        ssd.set('n');
        delay(1200);
        ssd.set('d');
        delay(1200);
        ssd.off();
        
        delay(1000);
        resetFunc(); //call reset
        
        break;
         }
    }
}

void ledOn(int i){
    digitalWrite(led,HIGH);
    if(i==0)
        {
        delay(100);
        digitalWrite(led,LOW);
        }
    }

int checkEnd(int k){
    int a=0;
    while(a<=k){
    char key = keypad.getKey();
    while(!key)
        {
        key = keypad.getKey();
        }
    
    key=key-'0';
    
    if(ran[a]!=key) 
        {
        return -1;
        }
        a++;
        delay(100);
        }
    return 0;
    }

void showNum(int a){
  switch(a){
      case 1:{ ssd.set(1); 
      break; }
      case 2:{ ssd.set(2); 
      break; }
      case 3:{ssd.set(3); 
      break; }
      case 4:{ssd.set(4); 
      break; }
      case 5:{ssd.set(5); 
      break; }
      case 6:{ssd.set(6); 
      break; }
      case 7:{ ssd.set(7); 
      break; }
      case 8:{ ssd.set(8); 
      break; }
      case 9:{ssd.set(9); 
      break; }
      case 0:{ ssd.set(0); 
      break; }
      }
  }

void loop() {
}
