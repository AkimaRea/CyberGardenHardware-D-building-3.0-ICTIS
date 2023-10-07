#pragma once
#include <Arduino.h>

class DP {
public:
  DP(int pin) {
    DPpin = pin;
  };
  void printResult() {
    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead(DPpin);
    double value = alpha * oldValue + (1 - alpha) * rawValue;
    Serial.print(rawValue);
    Serial.print(",");
    Serial.println(value);
    oldValue = value;
    delay(period);
  }
private:
  int DPpin;
  double alpha = 0.75;
  int period = 100;
  double change = 0.0;
  double minval = 0.0;
};
