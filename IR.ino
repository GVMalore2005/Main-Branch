#include<ESP8266WiFi.h>
#include<Adafruit_Sensor.h>
#include <ThingSpeak.h>
WiFiClient client;
long myChannelNumber = 2993281;
const char myWriteAPIKey[] = "GRR99NBQ7T0HYYU4";
int IR = D2;
void setup() {
  Serial.begin(9600);
  WiFi.begin("Tantraniketan_4G_EXT", "tantraniketan@2024");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  pinMode(IR,INPUT);
  ThingSpeak.begin(client);
}

void loop() {
  IR=digitalRead(D2);
 if(IR==HIGH)
 {
  digitalWrite(IR,HIGH);
 }
 else
 {
  digitalWrite(IR,LOW);
 }
 delay(150);
  Serial.println("Distance: " + (String) IR);
  ThingSpeak.writeField(myChannelNumber, 1, IR, myWriteAPIKey);
  delay(2000);
}
