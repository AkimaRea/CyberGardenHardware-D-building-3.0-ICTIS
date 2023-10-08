#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include "ThingSpeak.h"

class Cloud {
public:
  Cloud(const char* ssid, const char* password, unsigned long myChannelNumber, const char* myWriteAPIKey) {
    ssid = ssid;
    password = password;
    myChannelNumber = myChannelNumber;
    myWriteAPIKey = myWriteAPIKey;
  }
  void init() {
    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client);  // Initialize ThingSpeak
  }
  void sendData(float temp) {
    if ((millis() - lastTime) > timerDelay) {
      checkConnection();
      aggregateData(temp);
      writeToChannel();
      lastTime = millis();
    }
  }
private:
  void checkConnection() {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Attempting to connect");
      while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
        delay(5000);
      }
      Serial.println("\nConnected.");
    }
  }
  void writeToChannel() {
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (x == 200) {
      Serial.println("Channel update successful.");
    } else {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
  }
  void aggregateData(float temp) {
    ThingSpeak.setField(1, temp);
    // ThingSpeak.setField(2, humidity);
    // ThingSpeak.setField(3, pressure);
  }
  WiFiClient client;
  const char* ssid;
  const char* password;
  unsigned long myChannelNumber;
  const char* myWriteAPIKey;
  unsigned long lastTime = 0;
  unsigned long timerDelay = 30000;
};