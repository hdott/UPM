/*
Se citeşte un număr natural pe 8 biţi de la tastatură. 
Să se determine numărul de biţi egali cu 1 de pe poziţii pare.
*/

#include <stdio.h>

int times_biti_pozitii_pare(__uint8_t x)
{
    unsigned times=0;
    for(int i=0; i<8; ++i)
        if(x&(1<<i) && !(i%2))
            ++times;

    return times; 
}

void main()
{
    __uint8_t nr;
    printf("Introduceti un numar in limita [0,%u]: ",__UINT8_MAX__);
        scanf("%d",&nr), printf("\n");

    printf("Numarul bitilor (1) de pe pozitiile pare este: %u\n",times_biti_pozitii_pare(nr));
}
