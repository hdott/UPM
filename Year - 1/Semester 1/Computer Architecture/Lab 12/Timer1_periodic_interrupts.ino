//Programati timerul 1 sa generezze intreruperi periodice la fiecare 2 secunde:
//  - In rutina de tratare intrerupere generati un semnal sonor folosind un buzzer.
//  - Conectati un buton pe intrarea digitala D2, opriti/porniti timerul la apasarea butonului
//https://playground.arduino.cc/code/timer1

#include <TimerOne.h>
const int buzzer = 3;
const int button = 2;

int state = 0;

void setup()
{
  pinMode(buzzer,OUTPUT);
  
  Timer1.initialize(2000000);
  Timer1.attachInterrupt(rutina);
}

void loop()
{
  noTone(buzzer);

  read_button();
  if(state)
    Timer1.resume();
  if(!state)
    Timer1.stop();
}

void rutina()
{
  Serial.println();
  tone(buzzer,1000);
}

void read_button()
{
  if(digitalRead(button))
    state = !state;

  while(digitalRead(button))
    ;
}
