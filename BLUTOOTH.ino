char val;
int bulb1=2;
int bulb2=3;
int bulb3=4;
int bulb4=5;
void setup() {
  pinMode(bulb1,OUTPUT);
  pinMode(bulb2,OUTPUT);
  pinMode(bulb3,OUTPUT);
  pinMode(bulb4,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
    val=Serial.read();
    Serial.println(val);
  }
  if(val=='A')
  {
    digitalWrite(bulb1,HIGH);
  }
  if(val=='B')
  {
    digitalWrite(bulb2,HIGH);
  }
   if(val=='C')
  {
    digitalWrite(bulb3,HIGH);
  }
    if(val=='D')
  {
    digitalWrite(bulb4,HIGH);
  }
   
  else{
    digitalWrite(bulb1,LOW);
    digitalWrite(bulb2,LOW);
    digitalWrite(bulb3,LOW);
    digitalWrite(bulb4,LOW);
  }
}
