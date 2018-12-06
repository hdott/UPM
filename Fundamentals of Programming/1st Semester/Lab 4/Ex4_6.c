/*
Se citește un număr real cu parte întreagă 0 și 8 zecimale. 
Să se afișeze numărul rezultat după eliminarea primelor două și ultimelor două zecimale.
*/

#include <stdio.h>

void main()
{
    double nr, rezultat;

    printf("Introduceti un numar real cu parte intreaga 0 si 8 zecimale:\n");
        printf("nr = "), scanf("%lf", &nr);

    int parte_zecimala, aux1;
    parte_zecimala = nr * 100000000; // transformam partea zecimala in intreg
    aux1 = parte_zecimala % 1000000; // luam numarul format din ultimele 6 cifre
    aux1 = aux1 / 100;               // luam numarul format din primele 4 cifre din cel de 6
    rezultat = (double)aux1 / 10000; // transformam noul intreg in zecimal

    printf("Rezultatul dupa eliminarea primelor si ultimelor doua zecimale este: %.8lf\n", rezultat);
}   
