#include "th_sensor.h"
// #include "pulse_sensor.h"
#define DHpin 2
#define DLpin 4
// #define DPpin 4

DHT dht(DHpin);
DL dl(DHpin);
// DP dp(DPpin);

void setup() {
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
  pinMode(DLpin, INPUT);
  // pinMode(DPpin, INPUT);
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);
}

void loop() {
  dht.printResult();
  dl.printResult();
  // dp.printResult();
}