//Scrieti un program care salveaza coordonatele citite de la un joystick,
//  la apasarea butonunlui incepand cu adresa 8 in EEPROM( nu mai des de o seconda, si maxim 4 scrieri).
//https://www.arduino.cc/en/Reference/EEPROM

#include <EEPROM.h>
const int button = 2;
const int VRx = 0;
const int VRy = 1;
const int i = 8;
const int j = 10;

uint16_t x = 0;
uint16_t y = 0;
int state = 0;

void setup()
{
  pinMode(button,INPUT);

  Serial.begin(9600);
}

void loop()
{
  read_coordinates();
}

struct Joystick
{
  unsigned x;
  unsigned y;
  byte button;
};  Joystick my, mynew;

void read_coordinates()
{
  if(!digitalRead(button))
  {
    my.x = analogRead(VRx);
    my.y = analogRead(VRy);
    my.button=0;
    EEPROM.put(4,my);
    state = !state;
  }
  
  while(!digitalRead(button))
    if(state)
    {
      state = !state;
      EEPROM.get(4,mynew);
      Serial.print(mynew.x);
      Serial.print("\t");
      Serial.println(mynew.y);
    }
}
