//4x7_segment_integer
//hex here is inverse
//0 -> led_segment ON
//1 -> led_segment OFF

int D[10][5] = {{0x0,0x23,0x25,0x29,0x31},
                {0x0,,0x23,0x25,0x29,0x31},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x23,0x25,0x29,0x31},
                {0x0,0x22,0x24,0x28,0x30},
                {0x0,0x22,0x24,0x28,0x30}};
int nr[10] =    {0x0,0xE4,0x90,0xC0,0x64,0x48,0x8,0xE0,0x0,0x40};
int M[5] = {0,0,0,0,0};

void setup()
{
//  2,3,4,5,6,7,8
//  A,B,C,D,E,F,G
//  9 ,10,11,12
//  D1,D2,D3,D4
//  13 - dec
  DDRD = DDRD | B11111100;
  DDRB = B00111111;
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0)
  {
      M[1] = Serial.read()-'0',delay(5);
      M[2] = Serial.read()-'0',delay(5);
      M[3] = Serial.read()-'0',delay(5);
      M[4] = Serial.read()-'0',delay(5);
      flush_extra();
  }

  print_nr();
}

void flush_extra()
{
  while(Serial.available()>0)
        Serial.read();
}

void print_nr()
{
  for(int i=4,j=4; i>=1; --i)
    if(M[i]==-49 || M[i]==35)
      ;
    else
      segment7(M[i],j--);
}

void transform_to_digit(int x)
{
  for(int i=0; i<5; ++i)
    M[i] = '#';
  int j=4;
  
  while(x/10!=0 || x%10!=0)
  {
    M[j--] = x%10;
    x /= 10;
  }
  
  print_nr();
}

void segment7(int x, int y)
{
  PORTD = nr[x];
  PORTB = D[x][y];
  delay(5);  
}
