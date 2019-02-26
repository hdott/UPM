/*
Se citește un număr de 5 cifre.
Să se afișeze numărul rezultat după eliminarea cifrei din mijloc.
*/

#include <stdio.h>

void main()
{
    int nr;

    printf("Introduceti un numar de 5 cifre:\n");
        printf("nr = "), scanf("%d", &nr);

    printf("\nNumarul rezultat dupa eliminarea cifrei din mijloc este: %d%d\n", nr/1000, nr%100);  
}
