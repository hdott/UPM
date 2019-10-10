/* Se citesc doua numere intregi din fisierul in.txt. Numerele sunt scrise pe linii
    diferite. Sa se scrie un program+comenzi linie de comanda care sa scrie suma si 
    produsul celor doua numere in fisierul out.txt
*/

// Programul se ruleaza cu comanda:
//  ./Ex1 < in.txt > out.txt
#include <stdio.h>

int main(int argc, char **argv){
    int nr1,
        nr2;

    scanf("%d %d", &nr1, &nr2);

    printf("Suma %d + %d este: %d\n", nr1, nr2, nr1+nr2);
    printf("Produsul %d * %d este: %d\n", nr1, nr2, nr1*nr2);

    return 0;
}