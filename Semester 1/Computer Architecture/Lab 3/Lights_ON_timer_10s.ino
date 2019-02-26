//Scrieti un program care rezolva iluminatul in casa scarilor.
//Seconecteaza 4 intrerupatoare si un LED.
//Orice intrerupator actionat va aprinde LED-ul, care ramane aprins 10 seconde de la ultima apasare.
//https://www.arduino.cc/en/tutorial/button
//https://www.arduino.cc/en/tutorial/blink
//https://www.arduino.cc/reference/en/language/functions/time/millis/

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;

int state = 0;
int timer = 0;
const int TIME = 10000;

void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
}

void loop()
{
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);

//Any button press will reset the timer of 10 seconds for the LED to stay on
//    by reading millis() into timer;
  if(button1State || button2State || button3State || button4State)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    timer = millis();
    state = 1;
  }
  
//Once 10 seconds pass, which is verified by constantly checking millis()-timer, without
//  any button being pressed, the timer resets to 0;
  if(millis()-timer >= TIME && state)
  {
    digitalWrite(LED_BUILTIN,LOW);
    timer = 0;
    state = 0; 
  }
}
