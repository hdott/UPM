/*
Se citeşte un număr natural pe 8 biţi de la tastatură. 
Să se determine suma biţilor egali cu 1.
*/

#include <stdio.h>

int suma_biti(__uint8_t x)
{
    unsigned suma=0;
    for(int i=0; i<8; ++i)
        if(x&(1<<i))
            suma += i;

    return suma; 
}

void main()
{
    __uint8_t nr;
    printf("Introduceti un numar in limita [0,%u]: ",__UINT8_MAX__);
        scanf("%d",&nr), printf("\n");

    printf("Suma bitilor (1) este: %u\n",suma_biti(nr));
}
