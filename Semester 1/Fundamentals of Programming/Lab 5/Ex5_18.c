/*
Să se generalizeze problemele 16 și 17 a. î. 
Un număr în baza zecimală să fie convertit în orice bază b și invers.
*/

#include <stdio.h>

int power(int x, int y)
{
    int rezultat = 1;
    for(int i = 0; i < y; ++i)
        rezultat *= x;

    return rezultat;
}

int baza10_to_bazaX(int x, int baza)
{
    int rezultat = 0;
    for(int i = 1; x/baza != 0 || x%baza != 0; i *= 10)
    {
        rezultat += (x % baza) * i;
        x = x / baza;
    }
    
    return rezultat;
}

int bazaX_to_baza10(int x, int baza)
{
    int rezultat = 0;
    for(int i = 0; x / 10 != 0 || x % 10 != 0; ++i)
    {
        rezultat += (x%10) * power(baza,i);
        x = x / 10;
    }

    return rezultat;
}

void main()
{
    int nr, baza, aux;

    printf("Introduceti un numar in baza.10:\n");
        printf("nr\t= "), scanf("%d", &nr);
    printf("Introduceti baza in care doriti numarul transformat:\n");
        printf("baza\t= "), scanf("%d", &baza);
    
    printf("\nNumarul %d in baza.%d este = %d\n", nr, baza, aux=baza10_to_bazaX(nr,baza));
    printf("Numarul %d in baza.10 este = %d\n", aux, bazaX_to_baza10(aux,baza));
}
