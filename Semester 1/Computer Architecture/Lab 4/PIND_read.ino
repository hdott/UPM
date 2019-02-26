//Pentru portul D declarati:
//pin 0 - intrare
//pin 1-3 - iesire
//pin 4-7 - intrare.
//La pinii de intrare 4-6 conectati 3 butoane.
//Scrieti un program care citeste valoarea de intrare prin registrul PIND si notati valoare bitului,
//daca aceste a fost declarat iesire, daca a fost declarat intrare, dar nu este conectat nici un echipament la acest pin.
//https://www.arduino.cc/en/Reference/PortManipulation

void setup()
{
  DDRD = B00001110;
  Serial.begin(9600); 
}

void loop()
{
//Print all the bits of PIND at the same time
  Serial.println(PIND,BIN);

//Print all the bits of PIND individually
  print_bit(PIND,1<<7);
  print_bit(PIND,1<<6);
  print_bit(PIND,1<<5);
  print_bit(PIND,1<<4);
  print_bit(PIND,1<<3);
  print_bit(PIND,1<<2);
  print_bit(PIND,1<<1);
  print_bit(PIND,1<<0);
  Serial.println();
}

void print_bit(int port, int mask)
{
  if(port & mask)
    Serial.print(1);
  else
    Serial.print(0);
}
