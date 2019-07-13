## LAB 12

- [Timer1_Digital_Clock](./Timer1_digital_clock.ino)
    > Realizati un ceas electronic cu precizia de secunde folosind afisajul de 4x7 segmente.
    >   - incrementarea secundelor se va realiza prin intreruperea generata de timer1.
    >   - in bucla principala se va realiza afisarea multiplexata a cifrelor.
    >   - adaugati comunicatia seriala pentru a confiura valoarea afisata, daca se trimite o noua valoare de forma mm.ss valoarea va fi afisata si la fiecare secunda incrementata.
- [Timer1_Periodic_Interrupts](./Timer1_periodic_interrupts.ino)
    > Programati timer1 sa genereze intreruperi periodice la fiecare 2 secunde:
    >   - in rutina de tratare intrerupere generati un semnal sonor folosind un buzzer
    >   - conectati un buton pe intrarea digitala D2, opriti/porniti timerul la apasarae butonului.