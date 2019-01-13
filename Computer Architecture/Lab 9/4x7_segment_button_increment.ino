//Conectat un buton pe o intrare digitala si scrieti un program care numara si afiseaza numarul de apasari distincte
//  ale butonului.

//A,B,C,D,E,F,G,decimal point work with inverse logic (0 = light ON)
//D1,D2,D3,D3 work normally (1 = light ON)

//first 4 are for decicontrol_segal OFF and the last 4 are for decicontrol_segal ON
//dec_poz[][0] it s 0 and it is not used
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
const int button = 1;

int control_seg[] = {'#','#','#','#','#'};
int number = 0;
int state = 0;

void setup()
{
  //segment A,B,C,D,E,F,G,D1,D2,D3,D4,dec
  //pins    2,3,4,5,6,7,8, 9,10,11,12,13
  DDRD = DDRD | B11111100;
  DDRB = B00011111;  
}

void loop()
{
  while(digitalRead(button))
    if(!state)
      state = !state;

  if(state)
  {
    ++number;
    state = !state;
  }
  
  transform_to_digit(number);
}

void print_nr()
{    
  for(int i=4,j=4; i>=0; --i)
    if(control_seg[i]==-49 || control_seg[i]==35)
      ;
    else if(control_seg[i]==-2)
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

void transform_to_digit(int x)
{
  for(int i=0; i<5; ++i)
    control_seg[i] = '#';
  int j=4;

  if(!x)
    control_seg[j] = 0;
  else
    while(x/10!=0 || x%10!=0)
    {
      control_seg[j--] = x%10;
      x /= 10;
    }
  
  print_nr();
}
