// Библиотеку для работы с радиомодулями скачиваем с сайта: https://iarduino.ru/file/280.html
#include <iarduino_RF433_Receiver.h>    // Подключаем библиотеку для работы с приёмником

iarduino_RF433_Receiver radioRX(3);    // Создаём объект radioRX с указанием пина приёмника
int rec[2];   // Создаём переменную для приёма темперауры
     
void setup() {
  Serial.begin(9600);    // открываем последовательный порт для мониторинга действий в программе
  radioRX.begin(1000);    // Устанавливаем скорость приёма данных
  radioRX.openReadingPipe(5);   // Открываем канал для приёма данных (значение может быть от 0 до 7)
  radioRX.startListening();   // Начинаем приём данных
}
     
void loop() {
  if(radioRX.available()) {    // Если приёмник получил данные
    radioRX.read(&rec, sizeof(rec));    // Читаем полученные данные с указанием размера пачки
    Serial.print("Температура = ");   // Выводим температуру на экран
    Serial.print(rec[0]);
    Serial.println(" C");
    Serial.print("Влажность = ");   // Выводим влажность на экран
    Serial.print(rec[1]);
    Serial.println("% \n");
  }
  delay (1000);
}
