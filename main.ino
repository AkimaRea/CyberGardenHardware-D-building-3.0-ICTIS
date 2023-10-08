#include "th_sensor.h"
// #include "light_sensor.h"
// #include "pulse_sensor.h"
#include "cloud_service.h"

#include <WiFi.h>
#include "ThingSpeak.h"

#define DHpin 2
// #define DLpin 12
// #define DPpin 12

double temp = 0.0;
// float humidity = 0.0;

const char* ssid = "Galaxy";        // your network SSID (name)
const char* password = "01234578";  // your network password

unsigned long myChannelNumber = 1639541;
const char* myWriteAPIKey = "PE1ZICX0054PIAFK";

Cloud cloud(ssid, password, myChannelNumber, myWriteAPIKey);

DHT dht(DHpin);
// DL dl(DLpin);
// DP dp(DPpin);

void setup() {
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
  // pinMode(DLpin, OUTPUT);
  // pinMode(DPpin, INPUT);
  // pinMode(20, OUTPUT);
  // digitalWrite(20, HIGH);
  cloud.init();
}

void loop() {

  temp = dht.printResult();
  // dl.printResult();
  // dp.printResult();
  cloud.sendData(temp);
}