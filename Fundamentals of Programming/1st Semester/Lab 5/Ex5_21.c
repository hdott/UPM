/*
Fie 4 tipuri de bacnote 100, 50, 10 și 5. 
Sa se determine numărul minim de bacnote prin care o sumă s (citită de la tastatura) poate fi plătită.
*/

#include <stdio.h>
#define B100 100
#define B50   50
#define B10   10
#define B5     5

void print_minimum(int x)
{
    int nr_b100, nr_b50, nr_b10, nr_b5, rest;
    nr_b100 = nr_b50 = nr_b10 = nr_b5 = 0;
    
    nr_b100 = x / B100;
        rest = x % B100;
    nr_b50  = rest / B50;
        rest = rest % B50;
    nr_b10  = rest / B10;
        rest = rest % B10;
    nr_b5   = rest / B5;
        rest = rest % B5;

    if(rest != 0 && nr_b5 != 0)         // conditie pentru cand restul != 0 si b5 = 1
        ++nr_b10, --nr_b5;              // creste b10 cu 1 si scade 1 din b5
    else if(rest != 0 && nr_b5 == 0)    // in ideea ca o bacnota de 10 e mai eficienta decat
        ++nr_b5;                        // 2 bacnote de 5 in cazul de fata
                                        // in caz de restul != 0 si b = 0 creste b5 cu 1
    printf("\nNumarul de bacnote necesar este:\n");
        printf("B100 = %d\n", nr_b100);
        printf(" B50 = %d\n", nr_b50);
        printf(" B10 = %d\n", nr_b10);
        printf("  B5 = %d\n", nr_b5);
}

void main()
{
    int suma;

    printf("Introduceti o suma de bani:\n");
        printf("suma = "), scanf("%d", &suma);

    print_minimum(suma);
}
