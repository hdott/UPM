#define tempPin 1
int reading;
float cel, farh;

void setup()
{
  analogReference(INTERNAL);
  Serial.begin(9600);  
}

void loop()
{
  reading = analogRead(tempPin);
  cel = reading / 9.31;
  farh = (cel*9/5)+32;
  
  print_cel_farh();
  delay(1000);
}

void print_cel_farh()
{
  Serial.print("Temp_C = ");
  Serial.print(cel);
  Serial.print("\t");
  Serial.print("Temp_F = ");
  Serial.println(farh);
}
