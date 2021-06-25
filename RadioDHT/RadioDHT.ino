// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>
DHT dht(2, DHT11);    // указываем пин датчика и тип сенсора (DHT11, DHT21, DHT22)

#include <iarduino_RF433_Transmitter.h> // Подключаем библиотеку для работы с передатчиком
#include <iarduino_RF433_Receiver.h>  // Подключаем библиотеку для работы с приёмником

iarduino_RF433_Transmitter radioTX(4);  // Создаём объект radioTX с указанием пина передатчика
iarduino_RF433_Receiver    radioRX(3);  // Создаём объект radioRX с указанием пина приёмника
int trans[2]; // Создаём переменную для передачи температуры
int rec[2];  // Создаём переменную для приёма темперауры
     
void setup() {
  Serial.begin(9600);    // открываем последовательный порт для мониторинга действий в программе
  dht.begin();
  radioTX.begin(1000);  // Устанавливаем скорость передачи данных
  radioTX.openWritingPipe(5); // Открываем канал для передачи данных (значение может быть от 0 до 7)
  radioRX.begin(1000); // Устанавливаем скорость приёма данных
  radioRX.openReadingPipe(5); // Открываем канал для приёма данных (значение может быть от 0 до 7)
  radioRX.startListening(); // Начинаем приём данных
}
     
void loop() {
  dht.read();    // считывание данных с датчика
  switch(dht.getState()) {    // проверяем состояние данных
    case DHT_OK:    // выводим показания влажности и температуры
      trans[0] = dht.getTemperatureC();
      radioTX.write(&trans, sizeof(trans)); // Отправляем данные с указанием размера пачки
      trans[1] = dht.getHumidity();
      radioTX.write(&trans, sizeof(trans)); // Отправляем данные с указанием размера пачки
    
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
  delay (200);

  if(radioRX.available()) {  // Если приёмник получил данные
    radioRX.read(&rec, sizeof(rec));  // Читаем полученные данные с указанием размера пачки
    Serial.print("Temperature = ");  // Выводим данные на экран
    Serial.print(rec[0]);
    Serial.println(" C \t");
    Serial.print("Humidity = ");  // Выводим данные на экран
    Serial.print(rec[1]);
    Serial.println(" %");
    Serial.println("");
  }
  delay (1000);
}
