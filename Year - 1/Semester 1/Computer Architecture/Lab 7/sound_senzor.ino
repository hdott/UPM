//Cititi avloarea senzorului si afisati pe interfata seriala.
//La comanda vocala porniti redarae unei secvente de sunet (melodie) pe buzzer)
//https://create.arduino.cc/projecthub/iotboys/control-led-by-clap-using-arduino-and-sound-sensor-e31809
//https://www.arduino.cc/en/Tutorial/toneMelody

#include "pitches.h"

const int sound_sensor_digital = 2;
const int buzzer = 3;

int Sound_Sensor = 0;

void setup()
{
  pinMode(sound_sensor_digital,INPUT);
  pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  Sound_Sensor = digitalRead(sound_sensor_digital);
  Serial.println(Sound_Sensor); 

  if(Sound_Sensor)
    playMelody();
}

// notes in the melody:
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void playMelody()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // stop the tone playing:
    noTone(buzzer);
  }
}
