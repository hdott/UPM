//Conectati un joystick si 2 LED-uri.
//Modificati intensitatea luminoasa a celor 2 LED-uri in functie de valorile citite pe axa x si y a joystickului.
//https://www.arduino.cc/en/tutorial/PWM
//https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
//https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

const int button = 2;
const int VRx = 0;
const int VRy = 1;
const int LED1 = 10;
const int LED2 = 11;

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

  analogWrite(LED1, x/4);
  analogWrite(LED2, y/4);
}

void print_coordinates_button()
{
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(digitalRead(button));
}
