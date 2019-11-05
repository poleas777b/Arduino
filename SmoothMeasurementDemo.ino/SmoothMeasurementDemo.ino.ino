/*
  Smooth MAX6675 Thermocouple

  Reads a temperature from the MAX6675 thermocouple,
  smooth and displays it in the default Serial.

  https://github.com/YuriiSalimov/MAX6675_Thermocouple

  Created by Yurii Salimov, May, 2019.
  Released into the public domain.
*/
#include <Thermocouple.h>
#include <MAX6675_Thermocouple.h>
#include <SmoothThermocouple.h>

#define SCK_PIN 26
#define CS_PIN 24
#define SO_PIN 22

/**
  Smoothing factor of a temperature value.
*/
#define SMOOTHING_FACTOR 5
Thermocouple* thermocouple = NULL;


// список выводов Arduino для подключения к разрядам a-g
// семисегментного индикатора
int pins[2][8]={{23,25,27,29,31,33,35,37},{39,41,43,45,47,49,51,53}};
// значения для вывода цифр 0-9
byte numbers[10] = { B10001000, B11101011, B01001100, B01001001, B00101011,
B00011001, B00011000, B11001011, B00001000, B00001001};




// the setup function runs once when you press reset or power the board
void setup() {
//  Serial.begin(9600);

  Thermocouple* originThermocouple = new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN);
  thermocouple = new SmoothThermocouple(originThermocouple, SMOOTHING_FACTOR);

  /* OR
    thermocouple = new SmoothThermocouple(
      new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN),
      SMOOTHING_FACTOR
    );
  */
  // Сконфигурировать контакты как выходы
for(int p=0; p<2; p++){
  for(int i=0;i<8;i++)
  pinMode(pins[p][i],OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  
  // Reads temperature
  const double celsius = thermocouple->readCelsius();
  // Output of information
  int cel = (int)celsius;
//  Serial.println(cel);


  showNumber(cel);
  

  delay(500); // optionally, only to delay the output of information in the example.
}

// функция вывода цифры на семисегментный индикатор
void showNumber(int num)
{
  int des =(int)num/10;
  int cels =(int)(num - (des*10));
  for(int i=0;i<8;i++)
  {
    if(bitRead(numbers[des],i)==HIGH) // зажечь сегмент
    digitalWrite(pins[0][i],HIGH);
    else // потушить сегмент
    digitalWrite(pins[0][i],LOW);
  }

  for(int i=0;i<8;i++)
  {
    if(bitRead(numbers[cels],i)==HIGH) // зажечь сегмент
    digitalWrite(pins[1][i],HIGH);
    else // потушить сегмент
    digitalWrite(pins[1][i],LOW);
  }
}
