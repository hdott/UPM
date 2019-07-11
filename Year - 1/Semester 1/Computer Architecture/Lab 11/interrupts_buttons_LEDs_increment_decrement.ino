//Conectati doua butoane pe pinii digitali 2,3 si 8 LED-uri pe pinii digitali 4-12.
//La pornire este aprins primul LED.
//La fiecare apasare pe butonul de pe pinul 2 (intrerupere generata pe frontul cazator) se va
//  deplasa la stanga pozitia LED-ului aprins, iar pentru butonul de pe pinul 3 la dreapta.
//Se declara variabila globala volatila directie, care va fi modificata in rutinele de intrerupere si testata in
//  bucla principala (loop).
//directie = 0 -> deplasare stanga
//directie = 1 -> deplasare dreapta
//https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/

const int button1 = 2;
const int button2 = 3;
const int LED[] = {4,5,6,7,8,9,10,11};

volatile int directie = 0;
volatile int state = 0;

int x = 0;

void setup()
{
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  for(int i=0; i<8; ++i)
    pinMode(LED[i],OUTPUT);

  attachInterrupt(digitalPinToInterrupt(button1),directie_stanga,FALLING);
  attachInterrupt(digitalPinToInterrupt(button2),directie_dreapta,FALLING);
  
  digitalWrite(LED[0],HIGH);
}

void loop()
{
//  Serial.println(digitalRead(button1));
  if(!directie && state)
  {
    digitalWrite(LED[x],LOW);
    ++x;
    check_bounds();
    digitalWrite(LED[x],HIGH);
    state = !state;
  }
  else if(directie && state)
  {
    digitalWrite(LED[x],LOW);
    --x;
    check_bounds();
    digitalWrite(LED[x],HIGH);
    state = !state;
  }
}

void directie_stanga()
{
  directie = 0;
  state = !state;
}

void directie_dreapta()
{
  directie = 1;
  state = !state;
}

void check_bounds()
{
  if(x==-1)
    x = 7;
  if(x==8)
    x = 0;
}
