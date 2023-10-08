#include "th_sensor.h"
#include "light_sensor.h"
#include "pulse_sensor.h"
// #include "cloud_service.h"

// pins defined by gpios' number
#define DHpin 15
// #define DLpin 12
// #define DLPowerPlu sPin 13
#define DPPin 26
#define DPPowerPlusPin 14
#define DPPowerMinusPin 27

// double temp = 0.0;
// float humidity = 0.0;
// const char* ssid = "Galaxy";        // your network SSID (name)
// const char* password = "012345678";  // your network password
// unsigned long myChannelNumber = 1639541;
// const char* myWriteAPIKey = "PE1ZICX0054PIAFK";
// Cloud cloud(ssid, password, myChannelNumber, myWriteAPIKey);

DHT dht(DHpin);
DP dp(DPPin);
// DL dl(DLpin);

void setup() {
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);

  pinMode(DPPin, INPUT);
  pinMode(DPPowerPlusPin, OUTPUT);
  pinMode(DPPowerMinusPin, INPUT);
  digitalWrite(DPPowerPlusPin, HIGH);
  digitalWrite(DPPowerMinusPin, LOW);

  // pinMode(DLpin, OUTPUT);
  // pinMode(DLPowerPlusPin, OUTPUT);
  // digitalWrite(DLPowerPlusPin, HIGH);

  // pinMode(13, OUTPUT);
  // digitalWrite(13, HIGH);
  // cloud.init();
}

void loop() {
  dht.printResult();
  dp.printResult();
  // dl.printResult();
  // temp = dht.getValue();
  // cloud.sendData(temp);
}