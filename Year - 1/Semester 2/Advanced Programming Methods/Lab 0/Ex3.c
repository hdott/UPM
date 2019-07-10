/*
 * Sa se defineasca un subprogram care primeste ca parametru un numar natural n,
 *  numara si afiseaza toti divizorii lui n. Sa se apelee aceasta functie de 3 ori
 *  cu diferite valori ale lui n. (Valorile lui n vor fi citite de la tastatura)
 */

#include <stdio.h>
#define REPETITII 3

void print_all_divisors(unsigned n);    //function prototype

int main(void)
{
    unsigned n;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un numar natural: ");
            scanf("%u",&n);
        print_all_divisors(n);
    }

    return 0;
}

// prints all divizors of n
void print_all_divisors(unsigned n)
{
    printf("Divizorii lui %u sunt: ",n);
        for(unsigned i=2; i<n; ++i)
            if(!(n%i))  // if(n%i == 0)
                printf("%u ",i);
    printf("\n");
}