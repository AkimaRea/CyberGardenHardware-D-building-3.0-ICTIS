#pragma once
#include <Arduino.h>

class DP {
public:
  DP(int pin) {
    DPpin = pin;
  };
  void calcValue() {
    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead(DPpin);
    value = (alpha * oldValue + (1 - alpha) * rawValue)/10;
    oldValue = value;
    delay(period);
  }
  
  double getValue() {
    return value;
  }
private:
  double value;
  int DPpin;
  double alpha = 0.75;
  int period = 100;
  double change = 0.0;
  double minval = 0.0;
};
