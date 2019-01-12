//Conectati 6 LED-uri pe portul D (pinii 2-7), si scrieti un program care aprinde LED-urile cu numar par,
//  iar la fiecare secunda schimba starea tuturor LED-urilor.
//https://www.arduino.cc/en/Reference/PortManipulation

const int DELAY = 1000;

void setup()
{
  DDRD = DDRD | B11111100;  
}

void loop()
{
  PORTD = B10101000;
  delay(DELAY);
  PORTD = B01010100;
  delay(DELAY);
}
