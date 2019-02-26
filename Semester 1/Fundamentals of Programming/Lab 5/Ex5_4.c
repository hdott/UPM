/*
Se citește n, o valoare întreagă pozitivă. 
Să se determine toate numerele pe 4 cifre divizibile cu n.
*/

#include <stdio.h>
#define MIN 1000
#define MAX 10000

void while_loop(int x)
{
    int i = MIN;
    while(i < MAX)
    {
        if(i % x == 0)
            printf("%d ", i);
        ++i;
    }
}

void do_while_loop(int x)
{
    int i = MIN;
    do
    {
        if(i % x == 0)
            printf("%d ", i);
        ++i;
    }   while(i < MAX);
}

void for_loop(int x)
{
    for(int i = MIN; i < MAX; ++i)
        if(i % x == 0)
            printf("%d ", i);
}

void main()
{
    unsigned int n;

    printf("Introduceti o valoare intreaga pozitiva:\n");
        printf("n = "), scanf("%u", &n);

    printf("\nNumerele de 4 cifre divizibile cu %d sunt:\n", n);
    printf("\nWHILE\n");
        while_loop(n);
    printf("\n\nDO WHILE\n");
        do_while_loop(n);
    printf("\n\nFOR\n");
        for_loop(n);
    printf("\n");
}
