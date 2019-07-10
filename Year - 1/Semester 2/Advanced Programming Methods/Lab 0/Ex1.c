/*
 * Sa se defineasca un subprogram care primeste ca parametru un numar natural n si
 *  si afiseaza numerele de la 1 la n. Sa se apeleze aceasta functie de 3 ori cu
 *  diferite valori ale lui n. (Valorile lui n vor fi citite de la tastatura)
 */

#include <stdio.h>
#define REPETITII 3

void print_n_numbers(unsigned n);    //function prototype

int main(void)
{
    unsigned n;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un numar natural n: ");
            scanf("%u",&n);
            print_n_numbers(n);
    }

    return 0;
}

// prints the numbers from 1 to n
void print_n_numbers(unsigned n)
{
    for(unsigned i=1; i<=n; ++i)
        printf("%d ",i);
    printf("\n");
}