#define IRPin 2
#define buzzPin 3
int obstacle = HIGH;

void setup()
{
  pinMode(IRPin,INPUT);
  pinMode(buzzPin,OUTPUT); 
}

void loop()
{
  obstacle = digitalRead(IRPin);

  if(obstacle==LOW)
    tone(buzzPin,1000,2000);
}
