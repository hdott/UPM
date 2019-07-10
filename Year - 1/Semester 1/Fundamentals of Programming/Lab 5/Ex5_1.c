/*
Se citește n, o valoare întregă pozitivă. 
Să se afișeze toate numerele naturale de la 0 până la n separate prin spațiu.
*/

#include <stdio.h>

void main()
{
    unsigned int n, i = 0;

    printf("Introduceti o valoare intreaga pozitiva:\n");
        printf("n = "), scanf("%u", &n), printf("\n");

    printf("while:\t  ");
        while(i < n)
        {
            printf("%d ", i);
            ++i;
        }
    printf("\n");

    printf("do while: ");
        i = 0;
        do
        {
            printf("%d ", i);
            ++i;
        } while(i < n);
    printf("\n");

    printf("for:\t  ");
        for(i = 0; i < n; ++i)
            printf("%d ", i);
    printf("\n");
}
