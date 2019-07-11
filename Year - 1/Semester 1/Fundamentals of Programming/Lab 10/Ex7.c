/*
 * Sa se afiseze o piramida de tipul:
 * 1
 * 1 2
 * 1 2 3
 * ...
 * 1 2 3 ... n
 *  pentru o valoare a lui n transmisa ca parametru unui subprogram. Sa se apeleze
 *  aceasta functie de 3 ori cu diferite valori ale lui n. (Valorile lui n vor fi
 *  citite de la tastatura)
 */

#include <stdio.h>
#define REPETITII 3

void print_piramid_of_integers(unsigned n);  //function prototype

int main(void)
{
    int n;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un numar natural: ");
            scanf("%u",&n);
        print_piramid_of_integers(n);
    }

    return 0;
}

// prints piramid of consecutive integers
void print_piramid_of_integers(unsigned n)
{
    for(unsigned i=1; i<=n;++i)
    {
        for(unsigned j=1; j<=i; ++j)
            printf("%u ",j);
        printf("\n");
    }
}