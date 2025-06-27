#define BLYNK_TEMPLATE_ID "TMPL31yh85nwQ"
#define BLYNK_TEMPLATE_NAME "LED on and off"
#define BLYNK_AUTH_TOKEN "RERaqEK_FDgkEb1o-XFmEi3tXyJCOdvv"

#include<ESP8266WiFi.h>
#include<Adafruit_Sensor.h>
#include <Blynk.h>
WiFiClient client;

char auth [] = BLYNK_AUTH_TOKEN;
char ssid[]="Tantraniketan_4G_EXT";
char pass[]="tantraniketan@2024";

BLYNK_WRITE(V0){
  digitalWrite(D8,param.asInt());
}

BLYNK_WRITE(V1){
  digitalWrite(D3,param.asInt());
}

void setup() {
  // put your setup code here, to run once:
   pinMode(D8, OUTPUT);
  pinMode(D3, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN,"Tantraniketan_4G_EXT" ,"tantraniketan@2024", "blynk.cloud", 80);


}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
