#pragma once
#include <Arduino.h>

class DHT {
public:
  DHT(int DHpin = 2) {
    setPin(DHpin);
  }
  float value = 0.0;
  void start_test() {
    digitalWrite(DHpin, LOW);  //Потяните вниз шину, чтобы отправить сигнал запуска
    delay(30);                 //Задержка превышает 30 мс, так что DHT 11 может обнаружить сигнал запуска
    digitalWrite(DHpin, HIGH);
    delayMicroseconds(40);  //Дождитесь ответа DHT11
    pinMode(DHpin, INPUT);
    while (digitalRead(DHpin) == HIGH);
    delayMicroseconds(80);  // DHT11 реагирует, потянув шину низко на 80 микрсек.

    if (digitalRead(DHpin) == LOW)
      delayMicroseconds(80);     //DHT11 подтянут 80 микрсек, чтобы начать отправку данных;
    for (int i = 0; i < 5; i++)  //При получении данных о температуре и влажности контрольные биты не учитываются;
      dat[i] = read_data();
    pinMode(DHpin, OUTPUT);
    digitalWrite(DHpin, HIGH);  //После завершения отпускаем шины данных, ожидая, когда хост начнет следующий сигнал
  }
  void setPin(int pin) {
    DHpin = pin;
  }
  void calcResult() {
    char str[10] = "";
    char str2[10] = "";
    start_test();
    itoa(dat[0],str2, DEC);
    itoa(dat[2],str, DEC);
    value_humidity = float(strtod(str2,NULL));
    value_temp = float(strtod(str,NULL));
    delay(1000);
  }
  float *getValue() {
    calcResult();
    float values[2] = {value_temp, value_humidity};
    return values;
  }  
private:
  float value_temp;
  float value_humidity;
  byte read_data() {
    byte i = 0;
    byte result = 0;
    for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW)
        ;                     // ждать 50 микрсек.
      delayMicroseconds(30);  //Продолжительность высокого уровня оценивается для определения того, являются ли данные " 0 " или "1"
      if (digitalRead(DHpin) == HIGH)
        result |= (1 << (8 - i));  //Высоко в начале, низко в посте
      while (digitalRead(DHpin) == HIGH)
        ;  //Данные '1', ожидание следующего бита приема
    }
    return result;
  };
  int DHpin = 2;
  byte dat[5];
};
