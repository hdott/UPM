/*
Se citeşte un număr natural stocat pe 16 biţi de la tastatură. 
Să se interschimbe octetul inferior cu octetul superior.
*/

#include <stdio.h>

void interschimba_octeti(__uint16_t *x)
{
    unsigned short schimba=*x,masca1,masca2;
    masca1 = schimba>>8;
    masca2 = schimba<<8;
    *x = masca1|masca2;
}

void print_binar(__uint16_t x, int size)
{
    for(int i=size-1; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void main()
{
    __uint16_t nr;
    printf("Introduceti un numar in limita [0,%u]: ",__UINT16_MAX__);
        scanf("%u",&nr),printf("\n");
    
    print_binar(nr,sizeof(__uint16_t)*8);
    interschimba_octeti(&nr);
    print_binar(nr,sizeof(__uint16_t)*8);
    printf("Numarul rezultat este: %u\n",nr);
}
