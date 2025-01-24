#include<EEPROM.h>
int addr=0;
int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  //pinMode(6,OUTPUT);
  pinMode(13,OUTPUT);
  
  int aa=(int)EEPROM.read(addr);
  if(aa==1)
  {EEPROM.write(addr,0);a=2;}
  else
  {EEPROM.write(addr,1);a=1;}
  Serial.println(aa);
  
  if(a==1)// off
  {digitalWrite(2,HIGH);digitalWrite(13,LOW);//digitalWrite(6,LOW);
  }
  else if(a==2)// on 
  {digitalWrite(2,LOW);digitalWrite(13,HIGH);//digitalWrite(6,HIGH);
  }
}




void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  char a1='1';
  a=(int)(Serial.read()-a1+1);
  Serial.println(a);
  if(a==1)// off
  {digitalWrite(2,HIGH);digitalWrite(6,LOW);digitalWrite(13,LOW);EEPROM.write(addr,0);}
  else if(a==2)// on 
  {digitalWrite(2,LOW);digitalWrite(6,HIGH);digitalWrite(13,HIGH);EEPROM.write(addr,1);}
  else 
  {}
  }
}
