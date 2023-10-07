#include "th_sensor.h"

int DHpin = 2; // pin  ввода/вывода
byte dat[5];   

byte read_data()
{
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW); // ждать 50 микрсек. 
      delayMicroseconds(30); //Продолжительность высокого уровня оценивается для определения того, являются ли данные " 0 " или "1"
      if (digitalRead(DHpin) == HIGH)
        result |= (1 << (8 - i)); //Высоко в начале, низко в посте
    while (digitalRead(DHpin) == HIGH); //Данные '1', ожидание следующего бита приема
    }
  return result;
}

void start_test()
{
  digitalWrite(DHpin, LOW); //Потяните вниз шину, чтобы отправить сигнал запуска
  delay(30); //Задержка превышает 30 мс, так что DHT 11 может обнаружить сигнал запуска
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40); //Дождитесь ответа DHT11
  pinMode(DHpin, INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80); // DHT11 реагирует, потянув шину низко на 80 микрсек.
  
  if(digitalRead(DHpin) == LOW)
    delayMicroseconds(80); //DHT11 подтянут 80 микрсек, чтобы начать отправку данных;
  for(int i = 0; i < 5; i++) //При получении данных о температуре и влажности контрольные биты не учитываются;
    dat[i] = read_data();
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //После завершения отпускаем шины данных, ожидая, когда хост начнет следующий сигнал
}

void setup()
{
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
}

void loop()
{
  start_test();
  Serial.print("Humdity = ");
  Serial.print(dat[0], DEC); //Отображает целочисленные биты влажности;
  Serial.print('.');
  Serial.print(dat[1], DEC); //Отображает десятичные знаки влажности;
  Serial.println('%');
  Serial.print("Temperature = ");
  Serial.print(dat[2], DEC); //Отображает целочисленные биты температуры;
  Serial.print('.');
  Serial.print(dat[3], DEC); //Отображает десятичные знаки температуры;
  Serial.println('C');
}
