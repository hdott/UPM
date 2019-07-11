/*
 * Sa se defineasca un subprogram care primeste ca parametru un numar natural natural
 *  n si afiseaza primii n termeni din sirul lui Fibonacci. Sa se apeleze aceasta
 *  functie de 4 ori cu diferite valori ale lui n. (Valorile lui n vor fi citite
 *  de la tastatura)
 */

#include <stdio.h>
#define REPETITII 4

void print_n_Fibonacci_numbers(unsigned n);     // function prototype

int main(void)
{
    unsigned n;

    for(int i=0; i<4; i++)
    {
        printf("Introduceti un numar natural: ");
            scanf("%u",&n);
        print_n_Fibonacci_numbers(n);
    }

    return 0;
}

// prints first n Fibonacci numbers
void print_n_Fibonacci_numbers(unsigned n)
{
    printf("[1]Fibonacci nr este: 1\n");
    printf("[2]Fibonacci nr este: 1\n");

    static long unsigned previous=1, before_previous=1, current;

    for(unsigned i=3; i<=n; ++i)
    {
        // computes the sum of the previous 2 numbers
        current = previous + before_previous;
        printf("[%u]Fibonacci nr este: %lu\n",i,current);

        before_previous = previous;
        previous = current;
    }
}