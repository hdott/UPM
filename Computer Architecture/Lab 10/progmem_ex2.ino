//Repetati programul de mai sus stocand acelasi tablou si citind memoria program octet cu octet folosind
//  functia: pgm_read_byte.
//Comparati cele doua moduri de citire de mai jos:
//  val1 = pgm_read_byte(valori+i);
//  val2 = pgm_read_byte(p+i);
//https://www.arduino.cc/en/Reference/EEPROM

#include <EEPROM.h>
const PROGMEM uint16_t valori[] = {1,2,3,4,5,6,7,8,9,10};

void setup()
{
  byte i, *p, val1, val2;
  p = (byte *)valori;

  Serial.begin(9600);
  for(int i=0; i<5; ++i)
  {
    Serial.print(pgm_read_byte(valori+i));
    Serial.print("\t");
  }
  Serial.println();

  for(int i=0; i<10; ++i)
  {
    Serial.print(pgm_read_byte(p+i));
    Serial.print("\t");
  }
  Serial.println();
}

void loop()
{
  
}
