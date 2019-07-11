//4x7_segment_integer
//hex here is inverse
//0 -> led_segment ON
//1 -> led_segment OFF
//this applies only for segment leds and decimal point

int D[10][9] = {{0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                {0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x23,0x25,0x29,0x31,0x3,0x5,0x9,0x11},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10},
                {0x0,0x22,0x24,0x28,0x30,0x2,0x4,0x8,0x10}};
int nr[10] =    {0x0,0xE4,0x90,0xC0,0x64,0x48,0x8,0xE0,0x0,0x40};
int M[5] = {'#','#','#','#','#'};
int dec=4, state=0, condition=0;

void setup()
{
//  2,3,4,5,6,7,8
//  A,B,C,D,E,F,G
//  9 ,10,11,12
//  D1,D2,D3,D4
  DDRD = DDRD | B11111100;
  DDRB = B00111111;
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0)
  {
    for(int i=0; i<5; ++i)
      M[i] = '#';
      
    M[0] = Serial.read()-'0';
    M[1] = Serial.read()-'0';
    M[2] = Serial.read()-'0';
    M[3] = Serial.read()-'0';
    M[4] = Serial.read()-'0';
    flush_extra();
  }
  Serial.print(M[0]),Serial.print("\t");
  Serial.print(M[1]),Serial.print("\t");
  Serial.print(M[2]),Serial.print("\t");
  Serial.print(M[3]),Serial.print("\t");
  Serial.println(M[4]);

  divide_in_individual_components(12345.343);
//  print_nr();
}

void flush_extra()
{
  while(Serial.available()>0)
        Serial.read();
}

void print_nr()
{    
  for(int i=4,j=4; i>=0; --i)
    if(M[i]==-49 || M[i]==35)
      ;
    else if(M[i]==-2)
      segment7(M[--i],(j--)+4);
    else
      segment7(M[i],j--);
}

void swap(int x, int y)
{
  int aux = M[x];
  M[x] = M[y];
  M[y] = aux;
}

void divide_in_individual_components(double x)
{ 
  //state is so that this function is ran only when needed
  if(!state)
  {
    double param, b, a;
    b = modf(x,&a);
    long int int_part      = (long int)a;
    float fract_part  = (float)b;
  
    //takes the digits from the integer part of the number
    //if it is longer than 4 digits it moves the digits to the right
    //showing only the first 4 digits of the number

    for(int i = 4; int_part/10!=0 || int_part%10!=0; --i)
    {
      if(i==0)
      {
        condition=1;
        for(int e1=4,e2=3; e1>0; --e1,--e2)
            swap(e1,e2);
        M[0] = '#';
            
        M[++i] = int_part%10;
        int_part /= 10;
      }
      else
      {
        M[i] = int_part%10;
        int_part /= 10;
      }
    }

    //moves the digits to the left of the vector
    
    if(M[0]=='#')
      for(int i=0; i<4; ++i) 
        for(int j=i+1; j<=4; ++j)
          if(M[j]!='#')
          {
            swap(i,j);
            break;
          }
    //if there are any slots out of 4 available 
    //inputs the decimal point (.) after the last digit into the vector
    //then inputs digits from the fractional part into the array untill all the slots are full
    
    for(int i=0,check=0; i<5; ++i)
      if(M[i]=='#' && check==0 && condition==0)
      {
        M[i]=-2;
        ++check;                 
      }
      else if(M[i]=='#' && check==1)
      {
        fract_part *= 10;
        M[i]=(int)fract_part;
        fract_part -= (int)fract_part;
      }
  }
  
  state=1;
  print_nr();
}

void segment7(int x, int y)
{
  PORTD = nr[x];
  PORTB = D[x][y];
  delay(5);  
}
