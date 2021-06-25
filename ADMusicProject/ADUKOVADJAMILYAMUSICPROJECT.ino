/*
 *  Author: Адукова Джамиля
 *  Проект мини игры на основе известных музыклаьных тем
 */

#include <pitches.h>
#include <themes.h>
void Play_Pirates()
{ 
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / Pirates_duration[thisNote];//конвертируем длительность во временную задержку
    tone(8, Pirates_note[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.05; //1.05 – tempo (музыкальный темп), увеличьте это число чтобы проигрывание стало более медленным
    delay(pauseBetweenNotes);
    noTone(8); //останавливаем музыку на контакте 8 
    }
}
void Play_CrazyFrog()
{
  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(8, CrazyFrog_note[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}
void Play_MarioUW()
{
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(8, MarioUW_note[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}
void Play_Titanic()
{
    for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / Titanic_duration[thisNote];//convert duration to time delay
    tone(8, Titanic_note[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 2.70;
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}
void setup() {
pinMode(2, INPUT_PULLUP); //подключаем кнопку 1 с внутренним подтягивающим резистором, аналогично для других кнопок 
pinMode(3, INPUT_PULLUP); //Button 2 with internal pull up
pinMode(4, INPUT_PULLUP); //Button 3 with internal pull up
pinMode(5, INPUT_PULLUP); //Button 4 with internal pull up
Serial.begin(9600);
}
void loop() {
    if (digitalRead(2)==0)
      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Pirates();  }
    if (digitalRead(3)==0)
      { Serial.println("Selected -> 'Crazy Frog' ");  Play_CrazyFrog();  }
    if (digitalRead(4)==0)
      { Serial.println("Selected -> 'Mario UnderWorld' ");  Play_MarioUW();  }
    if (digitalRead(5)==0)
      { Serial.println("Selected -> 'Titanic' ");  Play_Titanic();  }
}
