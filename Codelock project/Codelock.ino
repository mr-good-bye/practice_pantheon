#include <TM1637.h>
#include <Keypad.h>
#define CLK 3
#define DIO 2

TM1637 tm1637(CLK, DIO);
int nonP [4]= {1,1,1,1};
int b = 0;
int a = 0;
int SymbolC;
int Counter = 0;
int i = 0;
int Timer = 0;
unsigned long timerEFX;


const byte ROWS = 4; //число строк у нашей клавиатуры
const byte COLS = 4; //число столбцов у нашей клавиатуры
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},               //  здесь мы располагаем названия наших клавиш, как на клавиатуре,для удобства пользования
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //к каким выводам подключаем управление строками
byte colPins[COLS] = {11, 10, 9, 8}; //к каким выводам подключаем управление столбцами

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));// в интернетах написано, что для работы оператора random нужно указать ему искать значения в пустом аналоговм выходе (типо туда приходят несуществующие показания)
  tm1637.init();// объявление экранчика
tm1637.set(BRIGHTEST); // яркость экрана 


}
void loop() {
  int mass [4]; // ГЕНЕРАТОР СЛУЧАЙНЫХ ПАРОЛЕЙ
  mass [0] = (random(0, 9));
  for (int i = 1; i < 4; i++) {
    while (b != 1) {
      a = (random(0, 9));
      for (int i = 0; i < 4; i++) {
        if (a != mass[i]) {
          b++;
        }
      }
    }
    mass[i] = a;
  }

  //



  char customKey = customKeypad.getKey(); // ЕСЛИ ЗАРЕГЕСТРИРОВАНО НАЖАТИЕ, ТО СЧИТЫВАЕТСЯ ЦИФРА ,И ПЕРЕМЕННАЯ SymbolC принимает ее значение

  if (customKey) {
    int SymbolC = (customKey);
  }
  while (Counter < 4) {
    if (SymbolC == mass[Counter]) {
      tm1637.display(SymbolC);
      Counter++;
    } else {

      Counter = 0 ;
    }

  }

  //

  while (Timer < 11) {     //эффект после введения
    if (millis () - timerEFX > 1000) {
      timerEFX = millis();
      for (int i = 0; i < 4; i++); {
        tm1637.display(mass[i]);


      }
      Timer++;
    }
  }




}
