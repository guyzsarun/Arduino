const int nC4 = 262;
const int nD4=294;
const int nE4=330;
const int nF4=349;
const int nG4=392;
const int nA4=440;
const int nB4=494;
const int nC5=524;

const int note[]={nC5,nG4,nA4,nG4,0,nB4,nC5};

const int duration[]={4,8,8,4,4,4,4,4};

void setup()
  {
  }
  
void loop()
  {
   for (int i=0;i<8;i++)
      {
       int wait=1000/duration[i];
       tone(3,note[i]);
       delay(wait);
       noTone(3);
       delay(50);
      }
     noTone(3);
     delay(2000);
    
    
  }
