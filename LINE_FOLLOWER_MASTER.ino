
/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/


#include<Wire.h>
int x ;
#define LS 2      // left sensor
#define RS 3      // right sensor
int buzz=4;
int right=10;
int left=11;
int rear=12;


void setup()
{
   Wire.begin();
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(rear,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(left,OUTPUT);
 
}

void loop()
{

  Wire.beginTransmission(9);
  
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
      x=1;
    
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
   x=2;
   digitalWrite(right,HIGH);
   //tone(buzz,3000,50);
   delay(100);
   digitalWrite(right,LOW);
}
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    x=3;
    digitalWrite(left,HIGH);
   //tone(buzz,3000,50);
   delay(100);
   digitalWrite(left,LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    x=4;
    digitalWrite(rear,HIGH);
    delay(10);
    digitalWrite(rear,LOW);
  }
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
}
