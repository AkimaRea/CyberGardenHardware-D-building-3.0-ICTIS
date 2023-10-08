#pragma once
#include <Arduino.h>

class DL {
public:
  DL(int pin) {
    DLpin = pin;
  }
  void printResult() {
    // Считываем значение с фоторезистора на аналоговом входе A0
    value = analogRead(DLpin);
    Serial.println(DLpin);
  };
  void calcValue() {
    value = analogRead(DLpin);
  }
  int getValue() {
    calcValue();
    return value;
  }
private:
  int DLpin;
  int value = 0;
};
