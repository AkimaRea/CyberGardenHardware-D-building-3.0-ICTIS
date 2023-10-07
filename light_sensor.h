byte sensorPin = A0;
// Присваиваем имя для цифрового значения аналогового входа A0
// int округляет значения 
int value = 0;
void setup() {
  // Пин 3 со светодиодом будет выходом (англ. «output»)
  pinMode(ledPin, OUTPUT);
  // Пин A0 с фоторезистором будет входом (англ. «input»)
}
void loop() {
  // Считываем значение с фоторезистора на аналоговом входе A0
  value = analogRead(sensorPin);
  // value значение в диапозоне от 0 до 1023
  // Полученные значения на аналоговом входе A0 делим на 4 
  //чтобы уложиться в диопозон от 0 до 255
  data = value / 4;
  // Включаем светодиод с полученной ранее мощностью - от 0 до 255
  analogWrite(ledPin, data);
}

class DL {
  public:
  DL(int pin = 2) {
    DLpin = pin;
  }

  private:
  int DLpin;
  int value = 0;
};