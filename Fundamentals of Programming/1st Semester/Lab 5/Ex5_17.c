/*
Să se convertească un număr dat din baza 2 în baza 10, folosind înmulțirii puterilor.
*/

#include <stdio.h>

int power(int x, int y)
{
    int rezultat = 1;
    for(int i = 0; i < y; ++i)
        rezultat *= x;

    return rezultat;
}

int baza2_to_baza10(int x)
{
    int rezultat = 0;
    for(int i = 0; x / 10 != 0 || x % 10 != 0; ++i)
    {
        rezultat += (x%10) * power(2,i);
        x = x / 10;
    }

    return rezultat;

}

void main()
{
    int nr;
    
    printf("Introduceti un numar in baza.2 (de la dreapta la stanga) pentru a fi transformat in baza.10:\n");
        printf("nr = "), scanf("%d", &nr);

    printf("\nNumarul %d in baza.10 este: %d\n", nr, baza2_to_baza10(nr));
}
