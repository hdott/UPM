//Se conecteaza 8 LED-uri (LED0-LED7), 4 la pinii digitali 4-7, 4 la pinii digitali 8-11.
//Folosind operatiile cu porturi scrieti un program care citesti de la interfata seriala un numar intre
//  0-255 si aprinde combinatia de leduri corespunzatoare.
//https://www.arduino.cc/en/Reference/PortManipulation
//https://www.arduino.cc/reference/en/language/functions/communication/serial/

int x = 0;
int mask1 = 0;
int mask2 = 0; 

void setup()
{
  DDRD = DDRD | B11110000;
  DDRB = B00001111;
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0)
  {
    x = Serial.parseInt();
    Serial.read();                    //reads the '\n' character after the parseInt()
  }

  Serial.println(x,BIN);
  divide_byte();
}

void divide_byte()
{
  PORTD = x<<4;
  PORTB = x>>4;
}
