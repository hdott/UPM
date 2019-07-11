/*
Se citește n, o valoarea întreagă pozitivă. 
Să se afișeze suma și produsul primelor n numere naturale.
*/

#include <stdio.h>

void while_loop(int x)
{
    int i = 1;
    unsigned long long int sum = 0, prod = 1;
    while(i <= x)
    {
        sum = sum + i;
        prod = prod * i;
        ++i;
    }

    printf("Suma primelor %d numere este:\t %d\n", x, sum);
    printf("Produsul primelor %d numere este: %d\n", x, prod);
}

void do_while_loop(int x)
{
    int i = 1;
    unsigned long long int sum = 0, prod = 1;
    do
    {
        sum = sum + i;
        prod = prod * i;
        ++i;
    }   while(i <= x);

    printf("Suma primelor %d numere este:\t %d\n", x, sum);
    printf("Produsul primelor %d numere este: %d\n", x, prod);
}

void for_loop(int x)
{
    unsigned long long int sum = 0, prod = 1;
    for(int i = 1; i <= x; ++i)
    {
        sum = sum + i;
        prod = prod * i;
    }

    printf("Suma primelor %d numere este:\t %d\n", x, sum);
    printf("Produsul primelor %d numere este: %d\n", x, prod);
}

void main()
{
    unsigned int n;

    printf("Introduceti o valoare intreaga pozitiva:\n");
        printf("n = "), scanf("%u", &n);

    printf("\nWHILE\n");
        while_loop(n);
    printf("\nDO WHILE\n");
        do_while_loop(n);
    printf("\nFOR\n");
        for_loop(n);
}
