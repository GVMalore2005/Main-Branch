#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer Server(80);
int led = D8;
void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     WiFi.begin("Tantraniketan_4G_EXT","tantraniketan@2024");
     while(WiFi.status()!= WL_CONNECTED)
     {
      Serial.println("..");
      Serial.println("NodeMCU is connected");
      Serial.println(WiFi.localIP());
      pinMode(led,OUTPUT);
     }
}

void loop() {
  // put your main code here, to run repeatedly:
        client=Server.available();
        if(client==1)
        {
          String request = client.readStringUntil('\n');
          Serial.println(request);
          request.trim();
          if(request == "GET / ledon HTTP/1.1")
          {
            digitalWrite(led,HIGH);
          }
           if(request == "GET / ledoff HTTP/1.1")
          {
            digitalWrite(led,LOW);
          }
          
        }
       
}
