int BLUE=11;// Blue LED pin
int RED=12;// Red LED pin
int GREEN=10;// Green LED pin 
int Pump=9;// Pump pin 

int Received=0;
int GREEN_state =0;  
int RED_state = 0;
int BLUE_state = 0;
int Pump_state = 0;




void setup(){
  
  Serial.begin(9600);
  
  pinMode(RED,OUTPUT); 
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(Pump,OUTPUT);
  
}

void loop(){
 
 if(Serial.available()>0)
 { 
    Received = Serial.read();  
 }
if (RED_state == 0 && Received == '3') // When a 3 is received the Red LED will turn on
  {
    digitalWrite(RED,HIGH);
    RED_state=1;
    Received=0;  
  }
if (RED_state ==1 && Received == '3')// When a 3 is received again the Red LED will turn off
  {
    digitalWrite(RED,LOW);
    RED_state=0;
    Received=0;
  }
if (BLUE_state == 0 && Received == '1') // When a 1 is received the Blue LED will turn on
  {
    digitalWrite(BLUE,HIGH);
    BLUE_state=1;
    Received=0;  
  }
if (BLUE_state ==1 && Received == '1')// When a 1 is received again the Blue LED will turn off
  {
    digitalWrite(BLUE,LOW);
    BLUE_state=0;
    Received=0;
  }

if (GREEN_state == 0 && Received == '2')// When a 2 is received  the Green LED will turn on
  {
    digitalWrite(GREEN,HIGH);
    GREEN_state=1;
    Received=0;  
  }
if (GREEN_state ==1 && Received == '2')// When a 2 is received again the Green LED will turn off
  {
    digitalWrite(GREEN,LOW);
    GREEN_state=0;
    Received=0;
  }
  if (Pump_state ==1 && Received == '4')// When a 4 is received again the Water Pump will turn off
  {
    digitalWrite(Pump,LOW);
    Pump_state=0;
    Received=0;
  }
  if (Pump_state ==1 && Received == '4')// When a 4 is received again the Water Pump will turn on
  {
    digitalWrite(Pump,HIGH);
    Pump_state=0;
    Received=0;
  }
}
