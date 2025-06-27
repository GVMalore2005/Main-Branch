#include <DHT.h>
#include <ESP8266WiFi.h>
#include<Adafruit_Sensor.h>
#include <ThingSpeak.h>
DHT dht(D6, DHT11);
WiFiClient client;
long myChannelNumber = 2986552;
const char myWriteAPIKey[] = "RTLO2SFI7Y6VZXFX";

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
  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}
