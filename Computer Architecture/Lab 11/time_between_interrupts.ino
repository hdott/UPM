//Masurati durata dintre doua intreruperi folosind functia micros(),
//  si afisati valoare pe interfata seriala.
//https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/

const int button1 = 2;

volatile long timer = 0;
volatile int state = 0;
volatile int counter = 0;

void setup()
{
  pinMode(button1,INPUT);

  attachInterrupt(digitalPinToInterrupt(button1),rutina,FALLING);
  
  Serial.begin(9600);
}

void loop()
{
  if(state)
  {
    if(counter==2)
    {
      Serial.println(micros()-timer);
      counter = 0;
    }
    else
      ++counter;
      
    state = !state;
  }
}

void rutina()
{
  state = !state;
  if(!counter)
    timer = micros();
}
