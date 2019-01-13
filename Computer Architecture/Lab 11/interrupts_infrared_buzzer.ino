//Conectati senzorul de detectie obstacole bazat pe infrarosu pe pinul digital 2 si un buzzer pe pinul 3.
//La detectia unui obstacol se va genera un sunet de frecventa 1000Hz pentru 2 secunde.
//  Se va rezolva problema prin interogare (citire in bucla loop) si prin intreruperi
//https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/

const int infrared = 2;
const int buzzer = 3;

volatile int state = 0;

void setup()
{
  pinMode(infrared,INPUT);
  pinMode(buzzer,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(infrared),rutina,FALLING);
}

void loop()
{
  if(state)
  {
    tone(buzzer,1000,2000);
    noTone(buzzer);
  }
    
} 

void rutina()
{
  state = !state;
}
