/*
 * O functie care calculeaza cel mai mare divizor comun si cel mai mic multiplu
 *  comun a doua numere naturale. Numerele sunt introduse de la tastatura.
 * (Algoritmul lui Euclid)
 */

#include <stdio.h>

int cmmdc_cmmmc(int x, int y, int *cmmdc, int *cmmmc);

int main(void)
{
    int x, y;

    printf("Introduceti 2 numere pentru a afla cmmdc si cmmmc: ");
        scanf("%d%d",&x,&y);

    int cmmdc, cmmmc;
    cmmdc_cmmmc(x,y,&cmmdc,&cmmmc);

    printf("\nCMMDC = %d\n",cmmdc);
    printf("CMMMC = %d\n",cmmmc);

    return 0;
}

// finds cmmdc & cmmmc
int cmmdc_cmmmc(int x, int y, int *cmmdc, int *cmmmc)
{
    int r, a, b;
    a = x;
    b = y;

    while(b)    // while(r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    *cmmdc = a;
    *cmmmc = (x*y) / a;
}