/*
Să se calculeze factorial de n (n!) fără a utiliza funcțiile din math.h. 
n se citește de la tastură.
*/

#include <stdio.h>

void print_rezultat(int x, long long int y)
{
    printf("%d! = %lld\n", x, y);
}

void while_loop(int x)
{
    long long int factorial = 1;
    int i = 1;
    while(i <= x)
    {
        factorial = factorial * i;
        ++i;
    }

    print_rezultat(x,factorial);
}

void do_while_loop(int x)
{
    long long int factorial = 1;
    int i = 1;
    do
    {
        factorial = factorial * i;
        ++i;
    }   while(i <= x);

    print_rezultat(x,factorial);
}

void for_loop(int x)
{
    long long int factorial = 1;
    for(int i = 1; i <= x; ++i)
        factorial = factorial * i;

    print_rezultat(x,factorial);
}

void main()
{
    int n;

    printf("Introduceti un numar pentru a afla factorialul sau:\n");
        printf("n = "), scanf("%d", &n);

    printf("\nWHILE\n");
        while_loop(n);
    printf("\nDO WHILE\n");
        do_while_loop(n);
    printf("\nFOR\n");
        for_loop(n);
    printf("\n");
}
