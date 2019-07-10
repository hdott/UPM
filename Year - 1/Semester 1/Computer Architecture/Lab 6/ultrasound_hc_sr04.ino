//- Cititi durata impulsului si afisati valoarea in monitorul serial, in forma zecimala si binara
//- Care este valoarea cea mai mica si cea mai mare masurata?
//- Afisati in monitorul serial valoarea distantei, tratati si afisati si erorile

const int trig = 2;
const int echo = 3;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  Serial.begin(9600);
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

  Serial.print(time_traveled,DEC);
  Serial.print("\t");
  Serial.print(time_traveled,BIN);
  Serial.print("\t");
  if(distance_traveled < 2.58 || distance_traveled > 431)
    Serial.println("ERROR");
  else
    Serial.println(distance_traveled);
}
