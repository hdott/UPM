//Conectarea butoanelor.
//https://www.arduino.cc/en/tutorial/button

const int button1 = 2;
const int button2 = 3;

int button1State = 0;
int button2State = 0;

void setup()
{
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  Serial.print("B1 = ");
  Serial.print(button1State);
  Serial.print("\t");
  Serial.print("B2 = ");
  Serial.println(button2State);
}
