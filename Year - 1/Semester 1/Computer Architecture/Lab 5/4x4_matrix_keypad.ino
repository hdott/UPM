//Se declara 2 tablouri cu numarul pinului digital pentru coloane si linii:
//  const int row[] = {5,4,3,2}
//  const int col[] = {6,7,8,9}
//- Se afiseaza pe interfata seriala linia, coloana tastei apasate
//- O noua valoare va fi afisata numai daca s-a schimbat tasta apasata
//- Se va afisa codul tastei afisate folosind o matrice de corespondenta
//  static const char keymap[4][4] = {{'1','2','3','A'},
//                                    {'4','5','6','B'},
//                                    {'7','8','9','C'},
//                                    {'*','0','#','D'}}
//- Definiti combinatii special de 2 taste, 3 taste
//- Afisati un text pentru combinata de taste aleasa                                   
//https://www.google.com/search?q=4x4+matrix+arduino&source=lnms&tbm=isch&sa=X&ved=0ahUKEwiK95iYmejfAhVRZlAKHfFDCJ8Q_AUIDigB&biw=958&bih=964#imgdii=J1Ir6n_OvbnPzM:&imgrc=CggIQVBolp7FvM:

const int row[] = {2,3,4,5};
const int col[] = {6,7,8,9};

static const char key[4][4] = {{'1','2','3','A'},
                               {'4','5','6','B'},
                               {'7','8','9','C'},
                               {'*','0','#','D'}};

int new_key = 0;
int old_key = 1;
int state = 0;
                             
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

//  key_pressed() ;
//  key_pressed_if_newval();
}

void key_pressed()
{
  for(int i=0; i<4; ++i)
  {
    digitalWrite(row[i],0);
    
    for(int j=0; j<4; ++j)
      while(!digitalRead(col[j]))
      {
        if(!state)
        {
          print_key(i,j);
          state = !state;
        }
      }

    if(state)
    {
      state = !state;
      break;
    }
    digitalWrite(row[i],1);
  }
}

void print_key(int i, int j)
{
  Serial.print("key["),Serial.print(i),Serial.print("]["),Serial.print(j),Serial.print("]");
  Serial.print("\t");
  Serial.println(key[i][j]);
}

void key_pressed_if_newval()
{
  for(int i=0, j=0; i<4; ++i)
  {
    digitalWrite(row[i],0);
    
    for(j=0; j<4; ++j)
      if(!digitalRead(col[j]))
      {
        new_key = i*10 + j;
        break;
      }
    digitalWrite(row[i],1);
    if(new_key != old_key)
    {
      print_key(i,j);
      old_key = new_key;
    }
  }
}
