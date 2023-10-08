#pragma once
#include <Arduino.h>

class DF {
public:
  DF(int pin) {
    DFpin = pin;
  }
  void calcValue() {
    Serial.println("Not implemented");  
   }
  void getValue() {
    Serial.println("Not implemented");  
  }
private:
  int DFpin;
  int value = 0;
};
