## LAB 10

- [EEPROM_Joystick](./EEPROM_joystick.ino)
    > Scrieti un program care salveaza coordonatele citite de la un joystick, la apasarea butonului incepand cu adresa 8 in EEPROM (nu mai des de o secunda, si maxim 4 scrieri)
- [progmem_ex1](./progmem_ex1.ino)
    > Scrieti un program care declara un tablou de 10 numere intregi fara semn pe 2 octeti in memoria program. In functia setup() afisati pe interfata seriala continutul tabloului citind cuvinte pe 2 octeti, folosind functia: pgm_read_word.
- [progmem_ex2](./progmem_ex2.ino)
    > Repetati programul de mai sus stocand acelasi tablou si citind memoria program octet cu octet folosind functia: pgm_read_byte. Comparati cele doua moduri de citire de mai jos:
    >   - val1 = pgm_read_byte(valori+i);
    >   - val2 = pgm_read_byte(p+i)