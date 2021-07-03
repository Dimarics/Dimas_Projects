// Библиотеку для работы с датчиками серии DHT скачивать с https://github.com/amperka/TroykaDHT
// Библиотеку для работы с радиомодулями скачиваем с сайта: https://iarduino.ru/file/280.html
#include <TroykaDHT.h>
#include <iarduino_RF433_Transmitter.h>   // Подключаем библиотеку для работы с передатчиком

DHT dht(2, DHT11);    // указываем пин датчика и тип сенсора (DHT11, DHT21, DHT22)
iarduino_RF433_Transmitter radioTX(4);    // Создаём объект radioTX с указанием пина передатчика
int trans[2];   // Создаём переменную для передачи данных
     
void setup() {
  dht.begin();
  radioTX.begin(1000);    // Устанавливаем скорость передачи данных
  radioTX.openWritingPipe(5);   // Открываем канал для передачи данных (значение может быть от 0 до 7)
}
     
void loop() {
  dht.read();    // считывание данных с датчика
  switch(dht.getState()) {    // проверяем состояние данных
    case DHT_OK:    // выводим показания влажности и температуры
      trans[0] = dht.getTemperatureC();
      radioTX.write(&trans, sizeof(trans));   // Отправляем данные с указанием размера пачки
      trans[1] = dht.getHumidity();
      radioTX.write(&trans, sizeof(trans));   // Отправляем данные с указанием размера пачки
  }
  delay (50);
}
