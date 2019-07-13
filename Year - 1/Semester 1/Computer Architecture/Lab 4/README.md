## LAB 4

- [Binary_LED_light_ON](./Binary_LED_light_on.ino)
    > Se conecteaza 8 LED-uri (LED0-LED7), 4 la pinii digitali 4-7, 4 la pinii digitali 8-11. Folosind operatiile cu porturi, scrieti un program care citeste de la interfata seriala un numar intre 0-255 si aprinde combinatia de led-uri corespunzatoare.
- [Buttons_LEDs](./Buttons_LEDs.ino)
    > Conectati 2 butoane la pinii digitali 2, 3 si 4. LED-uri (LED0, LED1, LED2, LED3) pe pinii digitali 4-7. Scrieti un program care aprinde LED-urile corespunzatoare valorii citite de la combinatia de butoane.
- [LED_ON_switch_Par_Impar](./LED_ON_switch_par_impar.ino)
    > Conectati 6 LED-uri pe portul D (pinii 2-7) si scrieti un program care aprinde LED-urile cu numar par, iar la fiecare secunda schimba starea tuturor LED-urilor.
- [PIND_Read](./PIND_read.ino)
    > Pentru portul D declarati:
    >   - PIN 0     - intrare
    >   - PIN 1-3   - iesire
    >   - PIN 4-7   - intrare
    >   - La pinii de intrare 4-6 conectati 3 butoane.
    > Scrieti un program care citeste valoarea de la intrare prin registrul PIND si notati valoarea bitului, daca acesta a fost declarat la iesire, daca a fost declarat la intrare, dar nu este conectat nici un echipament la acest pin.