#include<IRremote.hpp>
int RECV_PIN=D2;
int red=D8;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(red,OUTPUT);
}

void loop()
{
  if(IrReceiver.decode())
  {
    auto value = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(value,HEX);
    IrReceiver.resume();
    
    if (value == 0xF50A7F80){
    digitalWrite(red,HIGH);
    }

    if (value == 0xE41B7F80){
    digitalWrite(red,LOW);
    }
  }
  delay(100);
}
