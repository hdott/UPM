//Folosind 3 butoane si 8 LED-uri, se va aprinde LED-ul corespunzator codului generat prin actionarea
  //celor 3 butoane.
//https://www.arduino.cc/en/tutorial/button
//https://www.arduino.cc/en/tutorial/blink

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
const int LED4 = 8;
const int LED5 = 9;
const int LED6 = 10;
const int LED7 = 11;
const int LED8 = 12;

int button1State = 0;
int button2State = 0;
int button3State = 0;

int LED = 0;
int state = 0;

void setup()
{
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
}

void loop()
{
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);

  transform_to_dec();
  LED_light_up();  
}

void LED_light_up()
{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW);
  digitalWrite(LED8,LOW);
  digitalWrite(LED,HIGH);
}

//000 = 0
//001 = 1
//010 = 2
//011 = 3
//100 = 4
//101 = 5
//110 = 6
//111 = 7
void transform_to_dec()
{
  if(button3State==0 && button2State==0 && button1State==0)
    LED = LED1;
  if(button3State==0 && button2State==0 && button1State==1)
    LED = LED2;
  if(button3State==0 && button2State==1 && button1State==0)
    LED = LED3;
  if(button3State==0 && button2State==1 && button1State==1)
    LED = LED4;
  if(button3State==1 && button2State==0 && button1State==0)
    LED = LED5;
  if(button3State==1 && button2State==0 && button1State==1)
    LED = LED6;
  if(button3State==1 && button2State==1 && button1State==0)
    LED = LED7;
  if(button3State==1 && button2State==1 && button1State==1)
    LED = LED8;
}
