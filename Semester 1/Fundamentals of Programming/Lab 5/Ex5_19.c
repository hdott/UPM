/*
Fie numitorul și numărătorul unei fracții, să se simplifice fracția.
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
    int numarator, numitor;

    printf("Introduceti 2 numere ce reprezinta numitorul si numaratorul unei fractii:\n");
        printf("numarator = "), scanf("%d", &numarator);
        printf("numitor\t  = "), scanf("%d", &numitor);

    printf("\nFractia %d / %d simplificata este %d / %d\n", numarator, numitor, numarator/cmmdc(numarator,numitor), numitor/cmmdc(numarator,numitor));
}
