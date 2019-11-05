// список выводов Arduino для подключения к разрядам a-g
// семисегментного индикатора
int pins[2][8]={{23,25,27,29,31,33,35,37},{39,41,43,45,47,49,51,53}};
// значения для вывода цифр 0-9
byte numbers[10] = { B10001000, B11101011, B01001100, B01001001, B00101011,
B00011001, B00011000, B11001011, B00001000, B00001001};
// переменная для хранения значения текущей цифры
int number=0;
void setup()
{
// Сконфигурировать контакты как выходы
for(int p=0; p<2; p++){
  for(int i=0;i<8;i++)
  pinMode(pins[p][i],OUTPUT);
  }
}
void loop()
{
showNumber(number);
delay(1000);
number=(number+1)%10;
}
// функция вывода цифры на семисегментный индикатор
void showNumber(int num)
{
  for(int k=0; k<2; k++){
  for(int i=0;i<8;i++)
  {
    if(bitRead(numbers[num],i)==HIGH) // зажечь сегмент
    digitalWrite(pins[k][i],HIGH);
    else // потушить сегмент
    digitalWrite(pins[k][i],LOW);
  }}
}
