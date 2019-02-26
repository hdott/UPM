#define trig 2
#define echo 3

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

  Serial.println(distance_traveled);
}
