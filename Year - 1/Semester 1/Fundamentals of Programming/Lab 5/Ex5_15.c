/*
Să se calculeze cmmd și cmmc a două numere naturale date de la tastatură.
*/

#include <stdio.h>

int cmmdc(int x, int y)
{
    int r;

    while(y)        //cat timp r != 0
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

void main()
{
    int a, b;

    printf("Introduceti 2 numere naturale:\n");
        printf("a = "), scanf("%d", &a);
        printf("b = "), scanf("%d", &b);

    printf("\nCMMDC(%d,%d) = %d\n", a, b, cmmdc(a,b));
    printf("CMMMC(%d,%d) = %d\n", a, b, (a*b)/cmmdc(a,b));    
}
