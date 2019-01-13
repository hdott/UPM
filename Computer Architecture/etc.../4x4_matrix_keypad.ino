int key[4][4] =  {{'1','2','3','A'},
                  {'4','5','6','B'},
                  {'7','8','9','C'},
                  {'*','0','#','D'}}; 
int row[4]    =   {2,3,4,5};
int col[4]    =   {6,7,8,9};

void setup()
{
  for(int i=0; i<4; ++i)
    pinMode(row[i],OUTPUT);
  for(int i=0; i<4; ++i)
    pinMode(col[i],INPUT_PULLUP);
    
  Serial.begin(9600);
}

void loop()
{
  for(int i=0; i<4; ++i)
    digitalWrite(row[i],1);

  int state = 0;
  for(int i=0; i<4; ++i)
  {
    digitalWrite(row[i],0);
    if(!state)
      for(int j=0; j<4; ++j)
        if(!digitalRead(col[j]));
        {
          Serial.println(key[i][j]);
          state=1;
          break;
        }
    else
    {
      delay(10);
      break;
    }
  }
}
