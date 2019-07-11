#define VRx 0
#define VRy 1
#define SW 2

void setup()
{
  pinMode(SW,INPUT);

  Serial.begin(9600);
}

void loop()
{
  int x, y, button;
  
  x = analogRead(VRx);
  y = analogRead(VRy);
  button = digitalRead(SW);

  print_coordinates;
}

void print_coordinates()
{
  Serial.print("x = ");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("y = ");
  Serial.print(y);
  Serial.print("\t");
  Serial.print("button = ");
  Serial.println(button);
}
