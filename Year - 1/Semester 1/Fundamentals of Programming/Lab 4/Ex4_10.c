/*
Se citesc 5 numere întregi de la tastatură. 
Să se afișeze valoarea maximă și valoarea minimă.
*/

#include <stdio.h>
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b

int maxim(int x, int y, int z, int u, int w)
{
    int aux1, aux2, aux3;
    aux1 = max(x,y);
    aux2 = max(z,u);
    aux3 = max(aux1,aux2);

    return max(aux3,w);
}

int minim(int x, int y, int z, int u, int w)
{
    int aux1, aux2, aux3;
    aux1 = min(x,y);
    aux2 = min(z,u);
    aux3 = min(aux1,aux2);

    return min(aux3,w);
}

void main()
{
    int n1, n2, n3, n4, n5;

    printf("Introduceti 5 numere intregi:\n");
        printf("n1 = "), scanf("%d", &n1);
        printf("n2 = "), scanf("%d", &n2);
        printf("n3 = "), scanf("%d", &n3);
        printf("n4 = "), scanf("%d", &n4);
        printf("n5 = "), scanf("%d", &n5);

    printf("\nValoarea maxima este:\t%d\n", maxim(n1,n2,n3,n4,n5));
    printf("Valoarea minima:\t%d\n", minim(n1,n2,n3,n4,n5));
}
