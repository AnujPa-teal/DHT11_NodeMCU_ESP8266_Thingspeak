#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

#define DHTPIN D2     // connect the output pin of dht11 to D2 pin of NodeMCU ESP8266

#define DHTTYPE DHT11    // write here DHT22 in case if you have DHT22 the white coloured sensor


const char *ssid =  "Hotspot/WiFi_SSID";     // enter your wifi/hotspot ssid name
const char *pass = "Hotspot/WiFi_PASSWORD";   // enter the password of your wifi
const char* apiKey = "Channel_apikey";        // enter thingspeak channel apiKey
const unsigned long THINGSPEAK_CHANNEL_ID = channel_id ;    // enter the thingspeak channel id
const char* server = "api.thingspeak.com";

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);

  dht.begin();

  WiFi.begin(ssid, password);

  ThingSpeak.begin(client);
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  ThingSpeak.setField(1, temperature);    // choose the field 1 in thingspeak channel as temperature
  ThingSpeak.setField(2, humidity);       // choose the field 2 in thingspeak channel as humidity

  int statusCode = ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, apiKey);

  if (statusCode == 200) {
    Serial.println("Data has been sent to ThingSpeak server successfully!");
  } 
  else {
    Serial.print("Data send error. Status code: ");
    Serial.println(statusCode);
  }
}
