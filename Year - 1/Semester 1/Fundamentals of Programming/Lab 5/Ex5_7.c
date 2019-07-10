/*
Se citesc n și m (numere întregi). 
Să se determine toate numerele naturale de 5 cifre divizibile cu n și m.
*/

#include <stdio.h>
#define MIN 10000
#define MAX 100000

void while_loop(int x, int y)
{
    int i = MIN;
    while(i < MAX)
    {
        if((i % x == 0) && (i % y == 0))
            printf("%d ", i);
        ++i;
    }
}

void do_while_loop(int x, int y)
{
    int i = MIN;
    do
    {
        if((i % x == 0) && (i % y == 0))
            printf("%d ", i);
        ++i;
    }   while(i < MAX);
}

void for_loop(int x, int y)
{
    for(int i = MIN; i < MAX; ++i)
        if((i % x == 0) && (i % y == 0))
            printf("%d ", i);
}

void main()
{
    int n, m;

    printf("Introduceti 2 numere intregi:\n");
        printf("n = "), scanf("%d", &n);
        printf("m = "), scanf("%d", &m);

    printf("Numerele de 5 cifre divizibile cu %d si %d sunt:\n", n, m);
    printf("\nWHILE\n");
        while_loop(n,m);
    printf("\n\nDO WHILE\n");
        do_while_loop(n,m);
    printf("\n\nFOR\n");
        for_loop(n,m);
    printf("\n");  
}
