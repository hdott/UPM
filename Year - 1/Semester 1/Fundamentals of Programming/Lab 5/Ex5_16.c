/*
Să se convertească un număr dat din baza 10 în baza 2, folosind algoritmul resturilor.
*/

#include <stdio.h>

int baza10_to_baza2(int x)
{
    int rezultat = 0;
    for(int i = 1; x/2 != 0 || x%2 != 0; i *= 10)
    {
        rezultat += (x % 2) * i;
        x = x / 2;
    }
    
    return rezultat;
}

void main()
{
    int nr;

    printf("Introduceti un numar natural pentru a fi transformat in baza.2:\n");
        printf("nr = "), scanf("%d", &nr);

    printf("\nNumarul %d in baza.2 (de la dreapta la stanga) este: %d\n", nr, baza10_to_baza2(nr));
}
