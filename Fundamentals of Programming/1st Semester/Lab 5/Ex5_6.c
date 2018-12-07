/*
Se citesc două numere naturale n și m. 
Să se calculeze n^m (ridicate la putere) fără a utiliza funcțiile din math.h.
*/

#include <stdio.h>

void print_rezultat(int x, int y, long long int z)
{
    printf("%d^%d = %lld\n", x, y, z);
}

void while_loop(int x, int y)
{
    int i = 0;
    long long int power = 1;
    while(i < y)
    {
        power = power * x;
        ++i;
    }

    print_rezultat(x,y,power);
}

void do_while_loop(int x, int y)
{
    int i = 0;
    long long int power = 1;
    do
    {
        power = power * x;
        ++i;
    }   while(i < y);

    print_rezultat(x,y,power);
}

void for_loop(int x, int y)
{
    long long int power = 1;
    for(int i = 0; i < y; ++i)
        power = power * x;

    print_rezultat(x,y,power);
}

void main()
{
    unsigned int n, m;

    printf("Introduceti 2 numere naturale:\n");
        printf("n = "), scanf("%d", &n);
        printf("m = "), scanf("%d", &m);

    printf("\nWHILE\n");
        while_loop(n,m);
    printf("\nDO WHILE\n");
        do_while_loop(n,m);
    printf("\nFOR\n");
        for_loop(n,m);
    printf("\n");
}
