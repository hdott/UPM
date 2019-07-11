//Conectati 2 butoane la pinii digitali 2,3 si 4,
//  LED-uri(LED0, LED1, LED2, LED3) pe pinii digitali 4-7.
//Scrieti un program care aprinde LED-urile corespunzatoare valorii citite de la combinatia de butoane.
//https://www.arduino.cc/en/Reference/PortManipulation

const int LED0 = B00010000;
const int LED1 = B00100000;
const int LED2 = B01000000;
const int LED3 = B10000000;

void setup()
{
  DDRD = DDRD | B11110000;
}

void loop()
{
  light_up_LED(); 
}

void light_up_LED()
{
  if(!(PIND & 1<<2) && !(PIND & 1<<3))
    PORTD = LED0;
  if(PIND & 1<<2 && !(PIND & 1<<3))
    PORTD = LED1;
  if(!(PIND & 1<<2) && PIND & 1<<3)
    PORTD = LED2;
  if(PIND & 1<<2 && PIND & 1<<3)
    PORTD = LED3;
}
