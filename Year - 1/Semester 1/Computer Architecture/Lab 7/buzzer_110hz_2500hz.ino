//Scrieti un program care genereaza o secventa de sunete de la 110Hz la 2500Hz, fiecare perioada
//  (corespunzatoare frecventei unui sunet) se va repeta de 200 de ori.
//https://www.arduino.cc/en/Tutorial/toneMelody
//https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
//https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/
//frequency = 440 Hz = 440 oscillations per second = 440 oscillations/second = 440/sec;
//Period = 1/frequency
//  1/440 sec = .00227 sec

float frequency[56] = {110.0,116.5,123.5,130.8,138.6,146.8,155.6,164.8,174.6,185.0,196.0,207.7,
                     220.0,233.1,246.9,261.6,277.2,293.7,311.1,329.6,349.2,370.0,392.0,415.3,
                     440.0,466.2,493.9,523.3,554.4,587.3,622.3,659.3,698.5,740.0,784.0,830.6,
                     880.0,932.3,987.8,1046.5,1108.7,1174.7,1244.5,1318.5,1396.9,1480.0,
                     1568.0,1661.2,1760.0,1864.7,1975.5,2093.0,2217.5,2349.3,2489.0,2500.0};

const int millisecond = 1000;
const int microsecond = 1000000;

const int buzzer = 3;

void setup()
{
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for(int i=0; i<56; ++i)
    sound_on(buzzer,frequency[i],200);
//  while(1)
//    digitalWrite(buzzer,LOW);
}

void sound_on(int pin, float frequency, unsigned long repetition)
{
  float period_up = (microsecond/2)/frequency;
  float period_down = (microsecond/2)/frequency;

  for(int i=0; i<repetition; ++i)
  {
    digitalWrite(pin,HIGH);
    delayMicroseconds(period_up);
    digitalWrite(pin,LOW);
    delayMicroseconds(period_down);
  }
}
