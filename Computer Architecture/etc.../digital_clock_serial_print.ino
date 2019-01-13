#include <TimerOne.h>
int m=0, s=0, state=0;

void setup(void)
{
  Timer1.initialize(999999);
  Timer1.attachInterrupt(digital_clock);
  Serial.begin(9600);
}

void digital_clock()
{  
  if(s==59)
    s=0,++m;
  else
    ++s;
  change_state();
}

void loop()
{
  if(state)
  {
    Serial.print(m),Serial.print(':'),Serial.println(s);
    change_state();
  }
}

void change_state()
{
  state = !state;
}
