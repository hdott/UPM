//Conectati doua butoane pe pinii digitali 2,3 si 8 LED-uri pe pinii digitali 4-12.
//La pornire este aprins primul LED.
//La fiecare apasare pe butonul de pe pinul 2 (intrerupere generata pe frontul cazator) se va
//  deplasa la stanga pozitia LED-ului aprins, iar pentru butonul de pe pinul 3 la dreapta.
//Se declara variabila globala volatila directie, care va fi modificata in rutinele de intrerupere si testata in
//  bucla principala (loop).
//directie = 0 -> deplasare stanga
//directie = 1 -> deplasare dreapta
//In locul butoanelor se va folosi senzorul de sunet.
//https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/

const int senzor_sunet = 2;
const int LED[] = {4,5,6,7,8,9,10,11};

volatile int state = 0;

int x = 0;

void setup()
{
  pinMode(senzor_sunet,INPUT);
  for(int i=0; i<8; ++i)
    pinMode(LED[i],OUTPUT);

  attachInterrupt(digitalPinToInterrupt(senzor_sunet),incrementeaza,FALLING);
  
  digitalWrite(LED[0],HIGH);
}

void loop()
{
  if(state)
  {
    digitalWrite(LED[x],LOW);
    ++x;
    check_bounds();
    digitalWrite(LED[x],HIGH);
    state = !state;
  }
}

void incrementeaza()
{
  state = !state;
}

void check_bounds()
{
  if(x==-1)
    x = 7;
  if(x==8)
    x = 0;
}
