## LAB 11

- [Interrupts_Buttons_LEDs_Increment_Decrement](./interrupts_buttons_LEDs_increment_decrement.ino)
    > Conectati doua butoane pe pinii digitali 2, 3 si 8 LED-uri pe pinii digitali 4-12. La pornire este aprins primul LED. La fiecare apasare pe butonul de pe pinul 2 ( intrerupere generata pe frontul cazator) se va deplasa la stanga pozitia LED-ului aprins, iar pentru butonul de pe pinul 3 la dreapta. Se declara variabila globala volatila `directie`, care va fi modificata in rutinele de intrerupere si testata in bucla principala (loop).
- [Interrupts_Infrared_Buzzer](./interrupts_infrared_buzzer.ino)
    > Conectati senzorul de detectie obstacole bazat pe infrarosu pe pinul digital 2 si un buzzer pe pinul 3. La detectia unui obstacol se va genera un sunet de frecventa 1000Hz pentru 2 secunde. Se va rezolva problema prin interogare (citire in bucla loop) si prin intreruperi.
- [Interrupts_Sound_Senzor_LEDs_Increment](./interrupts_sound_senzor_LEDs_increment.ino)
    > Conectati 2 butoane pe pinii digitali 2, 3 si 8 LED-uri pe pinii digitali 4-12. La pornire este aprins primul LED. La fiecare apasare pe butonul de pe pinul 2 (intrerupere generata pe frontul cazator) se va deplasa la stanga pozitia LED-ului aprins, iar pentru butonul de pe pinul 3 la dreapta. Se declara variabila globala volatila directie, care va fi modificata in rutinele de intrerupere si testata in bucla principala (loop).
- [Time_Between_Interrupts](./time_between_interrupts.ino)
    > Masurati durata dintre doua intreruperi folosind functia micros(), si afisati valoarea pe interfata seriala.