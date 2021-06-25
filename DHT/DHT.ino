// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>
DHT dht(2, DHT11);    // указываем пин датчика и тип сенсора (DHT11, DHT21, DHT22)
     
void setup() {
  Serial.begin(9600);    // открываем последовательный порт для мониторинга действий в программе
  dht.begin();
}
     
void loop() {
  dht.read();    // считывание данных с датчика
  switch(dht.getState()) {    // проверяем состояние данных
    case DHT_OK:    // выводим показания влажности и температуры
      Serial.print("Temperature = ");
      int i = dht.getTemperatureC();
      Serial.print(i);
      Serial.println(" C \t");
      Serial.print("Temperature = ");
      Serial.print(dht.getTemperatureK());
      Serial.println(" K \t");
      Serial.print("Temperature = ");
      Serial.print(dht.getTemperatureF());
      Serial.println(" F \t");
      Serial.print("Humidity = ");
      Serial.print(dht.getHumidity());
      Serial.println(" %");
      Serial.println("");
      break;
    case DHT_ERROR_CHECKSUM:    // ошибка контрольной суммы
      Serial.println("Checksum error");
      break;
    case DHT_ERROR_TIMEOUT:    // превышение времени ожидания
      Serial.println("Time out error");
      break;
    case DHT_ERROR_NO_REPLY:    // данных нет, датчик не реагирует или отсутствует
      Serial.println("Sensor not connected");
      break;
  }
  delay(1000);  // ждём две секунды
}
