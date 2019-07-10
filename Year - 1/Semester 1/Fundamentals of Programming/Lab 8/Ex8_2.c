/*
Se citeşte un număr natural pe 8 biţi de la tastatură. 
Să se afişeze reprezentarea binară a acestuia folosind operatorul de deplasare.
*/

#include <stdio.h>

void print_binar(__uint8_t x)
{
    for(int i=7; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void main()
{
    __uint8_t nr;
    printf("Introduceti un numar in limita [0,255]: ");
        scanf("%u",&nr), printf("\n");

    print_binar(nr);
}
