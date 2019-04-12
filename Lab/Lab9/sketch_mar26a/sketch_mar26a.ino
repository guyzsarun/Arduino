void setup(){
  stepper_init(); 
}

int step=0;



const int inA=4;
const int inB=5;
const int inC=6;
const int inD=7;

void stepper_init(){
 pinMode(inA,OUTPUT);
 pinMode(inB,OUTPUT);
 pinMode(inC,OUTPUT);
 pinMode(inD,OUTPUT); 
 no_step();
}

void no_step(){
  digitalWrite(inA,LOW);
  digitalWrite(inB,LOW);
  digitalWrite(inC,LOW);
  digitalWrite(inD,LOW);
}

void wave_step(int step){
 int phase[4][4]=
{
 {HIGH,LOW,LOW,LOW},
 {LOW,HIGH,LOW,LOW},
 {LOW,LOW,HIGH,LOW},
 {LOW,LOW,LOW,HIGH}
};


int *currphase=phase[step];

for (int i=0;i<4;i++)
{
 digitalWrite(4+i,currphase[i]); 
}
}


void full_step(int step){
 int phase[4][4]=
{
 {HIGH,HIGH,LOW,LOW},
 {LOW,HIGH,HIGH,LOW},
 {LOW,LOW,HIGH,HIGH},
 {HIGH,LOW,LOW,HIGH}
};

int *currphase=phase[step];

for (int i=0;i<4;i++)
{
 digitalWrite(4+i,currphase[i]); 
}
}
  
  
 void loop(){
 wave_step(step++);
 step%=4;
 delay(20);
 no_step();
 delay(1000); 
}
