

#define THRESHOLD 100

unsigned int sensorValues[6];

int flag;
int in1=8;
int in2=9;
int in3=10;
int in4=11;
int en1=0;
int en2=1;
int Rspeed;
int Lspeed;

void setup()
{
	delay(500);
	pinMode(A0,INPUT);
	pinMode(A1,INPUT);
	pinMode(A2,INPUT);
	pinMode(A3,INPUT);
	pinMode(A4,INPUT);
	pinMode(A5,INPUT);
	
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(en1, OUTPUT);
	pinMode(en2, OUTPUT);

    
	Move('F',0,0);

	    // turn off Arduino's LED to indicate we are through with calibration
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.


}

void sensorRead(){
	sensorValues[0]=analogRead(A0);
	sensorValues[1]=analogRead(A1);
	sensorValues[2]=analogRead(A2);
	sensorValues[3]=analogRead(A3);
	sensorValues[4]=analogRead(A4);
	sensorValues[5]=analogRead(A5);

        
        Serial.print(sensorValues[0]);
        Serial.print("   ");
        Serial.print(sensorValues[1]);
        Serial.print("   ");
        Serial.print(sensorValues[2]);
        Serial.print("   ");
        Serial.print(sensorValues[3]);
        Serial.print("   ");
        Serial.print(sensorValues[4]);
        Serial.print("   ");
        Serial.print(sensorValues[5]);
        Serial.println();
     delay(500);
}

void Linefollow()
{

        while(sensorValues[3]<THRESHOLD&&sensorValues[4]<THRESHOLD&&sensorValues[5]){
          if(flag==1)
          {
          	Lspeed=0;
                Rspeed=200;
          
          }
          else
          {
	        Lspeed=200;
                Rspeed=0;          
          
          }
           Move('F',Rspeed,Lspeed);  
            sensorRead();
          
          
        }
        while(sensorValues[3]>THRESHOLD&&sensorValues[4]>THRESHOLD&&sensorValues[5]){
          if(flag==1)
          {
          	Lspeed=0;
                Rspeed=0;
          
          }
          else
          {
	        Lspeed=0;
                Rspeed=0;          
          
          }
          // Move('F',Rspeed,Lspeed); 
           Move('B',Rspeed,Lspeed);
           delay(500);
           Move('L',150,0); 
            sensorRead();
          
          
        }
	if(sensorValues[5]>THRESHOLD){
		Lspeed=180;
                Rspeed=200;
                flag=1;
	}
	if(sensorValues[4]>THRESHOLD){
		Lspeed=200;
                Rspeed=200;
                flag=1;
	}
	if(sensorValues[3]>THRESHOLD){
		Lspeed=180;
                Rspeed=200;
                flag=0;
	}

	
 
	Move('F',Rspeed,Lspeed);  

}


void loop()
{
 sensorRead();
Linefollow();
}


void Move(char dir,int Rspeed,int Lspeed)
{

if(dir=='F')
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
  analogWrite(en1,Rspeed);
  analogWrite(en2,Lspeed);
  


}
if(dir=='B')
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
  
  analogWrite(en1,Rspeed);
  analogWrite(en2,Lspeed);




}
if(dir=='L')
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
  analogWrite(en1,Rspeed);
  analogWrite(en2,Lspeed);




}




}
