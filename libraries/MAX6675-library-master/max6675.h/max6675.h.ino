#include <max6675.h>

int thermoDO = 22;
int thermoCS = 24;
int thermoCLK = 26;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() 
{
    Serial.begin(9600);
    Serial.println("MAX6675 SERIAL TEST");
   
   // time for stabilization
   delay(1000);
}


void loop() 
{
   // current temperature readout
   Serial.print("Deg C = ");
   Serial.println(thermocouple.readCelsius());
   Serial.print("\t Deg F = ");
   Serial.println(thermocouple.readFahrenheit());
   Serial.println();

   delay(1000);
}
