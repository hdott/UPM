/*
Se citeşte un număr natural pe 32 biţi (m) şi un număr natural pe 8 biţi (n) de la tastatură. 
Să se implementeze rotaţia pe biţi al lui n de m ori. 
Primul bit din stânga devine ultimul bit din dreapta - rotaţie de la stânga (sau invers - rotaţie la dreapta).
*/

#include <stdio.h>

void print_binar(__uint8_t x, int size)
{
    for(int i=size-1; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void roteste_biti_dreapta(__uint8_t *x, __uint32_t times)
{
    for(int i=0; i<times; ++i)
    {
        unsigned masca = *x&(1<<0);
        *x >>= 1;
        *x |= masca<<7;
        print_binar(*x,8);
    }
}

void roteste_biti_stanga(__uint8_t *x, __uint32_t times)
{
    for(int i=0; i<times; ++i)
    {
        unsigned masca = *x&(1<<7);
        *x <<= 1;
        *x |= masca>>7;
        print_binar(*x,8);
    }
}

void main()
{
    __uint8_t n;
    __uint32_t m;

    printf("Introduceti un numar in limita [0,%u]: ",__UINT32_MAX__);
        scanf("%u",&m);
    printf("Introduceti un numar in limita [0,%u]: ",__UINT8_MAX__);
        scanf("%u",&n),printf("\n");

    getchar();  //capteaza ultimul enter
    printf("Selectati directia ('>' / '<'): ");
    char directie = getchar();printf("\n");
    
    if(directie=='>')
        roteste_biti_dreapta(&n,m);
    else if(directie=='<')
        roteste_biti_stanga(&n,m);
    else
        printf("Directia selectata nu este disponibila!\n");
}
