/*
Se cites de la tastatura doua numere formate din cel mult 50 de cifre.
Sa se afiseze suma lor.
Obs.
    Numerele vor fi stocate sub forma de tablou.(cifrele?)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 50

void main()
{
    char tablou[2][MAXLEN];

    puts("Introduceti 2 numere");

    printf("x = "), scanf("%50s",tablou[0]);
    printf("y = "), scanf("%50s",tablou[1]);

    long long x, y;
    x = atoll(tablou[0]);
    y = atoll(tablou[1]);

    printf("\nSuma %lld + %lld = %lld\n", x, y, x+y);
}
