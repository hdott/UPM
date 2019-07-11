//Conectati doua difuzoare si un joystick, 
//  modificati frecventa sunetului la cele doua difuzoare in functie de pozitia pe cele doua axe al joystickului.

const int button = 2;
const int VRx = 0;
const int VRy = 1;
const int buzzer1 = 3;
const int buzzer2 = 4;

int x = 0;
int y = 0;
int but = 0;

void setup()
{
  pinMode(button,INPUT);

  Serial.begin(9600);
}

void loop()
{
  x   = analogRead(VRx);
  y   = analogRead(VRy);
  but = digitalRead(button);

  sound_coordinate(buzzer1,x);
  sound_coordinate(buzzer2,y);
}

void print_coordinates_button()
{
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(digitalRead(button));
}

void sound_coordinate(int pin, int coordinate)
{
  if(coordinate)
    tone(pin,coordinate);
  else
    noTone(pin);
}
