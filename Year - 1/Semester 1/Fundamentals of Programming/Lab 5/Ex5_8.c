/*
Se citește n. Să se afișeze următorul triunghi de numere: 
1
1 2 
1 2 3 
… 
1 2 3 … n
*/

#include <stdio.h>

void while_loop(int x)
{
    int i = 1;      //variabila ce reprezinta randurile
    while(i <= x)
    {
        int j = 1;  //variabila ce reprezinta numerele pe fiecare rand
        while(j <= i)
        {
            printf("%d ", j);
            ++j;
        }
        printf("\n");

        ++i;
    }
}

void do_while_loop(int x)
{
    int i = 1;
    do
    {
        int j = 1;
        do
        {
            printf("%d ", j);
            ++j;
        }   while(j <= i);
        printf("\n");

        ++i;
    }   while(i <= x);
}

void for_loop(int x)
{
    for(int i = 1; i <= x; ++i)
    {
        for(int j = 1; j <= i; ++j)
            printf("%d ", j);
        printf("\n");
    }
}

void main()
{
    int n;

    printf("Introduceti un numar intreg:\n");
        printf("n = "), scanf("%d", &n);

    printf("\nWHILE\n");
        while_loop(n);
    printf("\nDO WHILE\n");
        do_while_loop(n);
    printf("\nFOR\n");
        for_loop(n);
    printf("\n");    
}
