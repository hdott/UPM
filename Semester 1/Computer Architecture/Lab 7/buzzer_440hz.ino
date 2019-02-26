//Generati un sunet de frecventa de 440Hz pentru o durata de 5 secunde
//https://www.arduino.cc/en/Tutorial/toneMelody
//https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
//https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/
//frequency = 440 Hz = 440 oscillations per second = 440 oscillations/second = 440/sec;
//Period = 1/frequency
//  1/440 sec = .00227 sec

const int millisecond = 1000;
const int microsecond = 1000000;
unsigned duration = 1;
const int buzzer = 3;

void setup()
{
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  sound_on(buzzer,440,5*millisecond);
  while(1)
    digitalWrite(buzzer,LOW);
}

void sound_on(int pin, float frequency, unsigned long duration)
{
  float period_up = (microsecond/2)/frequency;
  float period_down = (microsecond/2)/frequency;

  int timer=millis();
  while(millis()-timer<=duration)
  {
    digitalWrite(pin,HIGH);
    delayMicroseconds(period_up);
    digitalWrite(pin,LOW);
    delayMicroseconds(period_down);
  }
}
