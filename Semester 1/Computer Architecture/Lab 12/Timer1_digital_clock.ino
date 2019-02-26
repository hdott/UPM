//Realizati un ceas electronic cu precizia de secunde folosind afisajul de 4x7 segmente.
//  - Incrementarea secundelor se av realiza prin intreruperea generata de timer1.
//  - In bucla principala se va realiza afisarea multiplexata a cifrelor.
//  - Adaugati comunicatia seriala pentru a configura valoarea afisata,
//      daca se trimite o noua valoare de forma mm.ss valoarea va fi afisata
//      si la fiecare secunda va fi incrementata.
//https://playground.arduino.cc/code/timer1

#include <TimerOne.h>
const int dec_poz[10][9] = {{0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                            {0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                            {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10}};
const int nr[10] = {0x0,0xE4,0x90,0xC0,0x64,0x48,0x8,0xE0,0x0,0x40};

int control_seg[] = {'#','#','.','#','#'};
int x = 0;

volatile int minutes = 0;
volatile int seconds = 0;
volatile int state = 0;

void setup()
{
  //segment A,B,C,D,E,F,G,D1,D2,D3,D4,dec
  //pins    2,3,4,5,6,7,8, 9,10,11,12,13
  DDRD = DDRD | B11111110;
  DDRB = B00111111;  

  Timer1.initialize(999999);
  Timer1.attachInterrupt(digital_clock);
}

void loop()
{
   transform_to_digit_seconds_minutes();
}

void digital_clock()
{
  if(seconds == 59 && minutes == 59)
  {
    seconds = 0;
    minutes = 0;
  }
  else if(seconds==59)
  {
    seconds = 0;
    ++minutes;
  }
  else
    ++seconds;

  state = !state;
}

void print_to_segment()
{    
  for(int i=4,j=4; i>=0; --i)
    if(control_seg[i]==-49 || control_seg[i]==35)
      ;
    else if(control_seg[i]=='.')
      segment7(control_seg[--i],(j--)+4);
    else
      segment7(control_seg[i],j--);
}

void segment7(int x, int y)
{
  PORTD = nr[x];
  PORTB = dec_poz[x][y];
  delay(5);  
}

void transform_to_digit_seconds_minutes()
{  
  if(state)
  {
    int j=4;
    int s = seconds;
    int m = minutes;
    
    if(s==0)
      for( ; j>=3; --j)
        control_seg[j] = 0;
    else if(s<10)
    {
      control_seg[j--] = s;
      control_seg[j--] = 0;
    }
    else
      while(s%10!=0 || s/10!=0)
      {
        control_seg[j--] = s%10;
        s/=10; 
      }

    --j;

    if(m==0)
      for( ; j>=0; --j)
        control_seg[j] = 0;
    else if(m<10)
    {
      control_seg[j--] = m;
      control_seg[j--] = 0;
    }
    else
      while(m%10!=0 || m/10!=0)
      {
        control_seg[j--] = m%10;
        m/=10;
      }

    state = !state;
  }

  print_to_segment();
}
