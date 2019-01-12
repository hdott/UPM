//Conectati 8 LED-uri si aprindeti un numar de LED-uri proportional cu distanta pana la obiect
//Ex:
//  - distanca mai mica de 5cm 1 LED aprins
//  - distanca mai mare de 400cm 8 LED-uri aprinse

const int trig = 2;
const int echo = 3;

int range = 0;

void setup()
{
  DDRD = DDRD | B11110100;
  DDRB = B00001111;
}

void loop()
{
  digitalWrite(trig,LOW);
    delay(2);
  digitalWrite(trig,HIGH);
    delay(10);
  digitalWrite(trig,LOW);

  long time_traveled = pulseIn(echo,HIGH);
  float distance_traveled = time_traveled * .034 / 2;

  transform_distance_light_up_LEDs(distance_traveled);
}

void transform_distance_light_up_LEDs(int x)
{  
  if(x>=5)
  {
    PORTD = PORTD | B00010000;
    PORTB = 0;
  }
  if(x>=15)
  {
    PORTD = PORTD | B00110000;
    PORTB = 0;
  }
  if(x>=40)
  {
    PORTD = PORTD | B01110000;
    PORTB = 0;
  }
  if(x>=70)
  {
    PORTD = PORTD | B11110000;
    PORTB = 0;
  }
  if(x>=100)
  {
    PORTD = PORTD | B11110000;
    PORTB = B00000001;
  }
  if(x>=150)
  {
    PORTD = PORTD | B11110000;
    PORTB = B00000011;
  }
  if(x>=200)
  {
    PORTD = PORTD | B11110000;
    PORTB = B00000111;
  }
  if(x>=300)
  {
    PORTD = PORTD | B11110000;
    PORTB = B00001111;
  }
}
