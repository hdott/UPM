/*
Să se convertească un număr dat din baza 10 în baza 2, folosind algoritmul resturilor.
*/

#include <stdio.h>

void print_baza2(int x)
{
    while(x/2 != 0 || x%2 != 0)
    {
        printf("%d",x%2);
        x = x / 2;
    }
    printf("\n");
}

void main()
{
    int nr;

    printf("Introduceti un numar natural pentru a fi transformat in baza.2:\n");
        printf("nr = "), scanf("%d", &nr);

    printf("\nNumarul %d in baza 2 este:\n", nr);
        print_baza2(nr);
}
