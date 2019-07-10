//Scrieti un program care declara un tablou de 10 numere intregi fara semn pe 2 octeti in memoria program.
//In functia setup() afisati pe interfata seriala continului tabloului citind cuvinte pe 2 octeti,
//  folosind functia: pgm_read_word.
//https://www.arduino.cc/en/Reference/EEPROM

#include <EEPROM.h>
const PROGMEM uint16_t valori[] = {1,2,3,4,5,6,7,8,9,10};

void setup()
{
  Serial.begin(9600);

  for(int i=0; i<10; ++i)
    Serial.println(pgm_read_word(valori+i));
}

void loop()
{
  
}
