#include<IRremote.hpp>
int RECV_PIN=3;
int green=13;
int white=12;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if(IrReceiver.decode())
  {
    auto value = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(value,HEX);
    IrReceiver.resume();
    
    if (value == 0xF50A7F80){
    digitalWrite(green,HIGH);
      digitalWrite(white,LOW);
      
    }
      if (value == 0xE41B7F80
){
    digitalWrite(green,LOW);
      digitalWrite(white,HIGH);
    } 
  }
  delay(100);
}
