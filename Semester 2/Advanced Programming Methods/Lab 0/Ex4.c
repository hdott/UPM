/*
 * Sa se defineasca un subprogram care primeste ca parametru un numar natural
 *  n si afiseaa rasturnatul lui. Sa se apeleze aceasta functie de 3 ori cu
 *  diferite valori ale lui n. (Valorile lui n vor fi citite de la tastatura)
 */

#include <stdio.h>
#define REPETITII 3

void print_nr_backwards(unsigned n);    //function prototype

int main(void)
{
    unsigned n;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un numar natural: ");
            scanf("%u",&n);
        print_nr_backwards(n);
    }

    return 0;
}

// prints a numbers backwards
void print_nr_backwards(unsigned n)
{
    printf("%u backwards is: ",n);
        while((n/10) || (n%10))     // while((n/10 != 0) || (n%10 != 0))
        {
            printf("%u",n%10);
            n/=10;
        }

    printf("\n");
}