//Cititi si afisati valorile analogice si cea digitala.
//Determinati valorile pentru punctele cardinale

const int button = 2;
const int VRx = 0;
const int VRy = 1;

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

  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(digitalRead(button));
}
