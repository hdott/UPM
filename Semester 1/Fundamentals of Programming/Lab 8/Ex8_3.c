/*
Se citeşte un număr întreg de la tastatură. 
Dacă valoarea bitului 2 este 1 atunci şa se seteze bitul 5, altfel să se reseteze bitul 7.
*/

#include <stdio.h>

void resetare_bit(int *x, int poz)
{
    *x&=~(1<<poz);
}

void setare_bit(int *x, int poz)
{
    *x|=(1<<poz);
}

void print_binar(int *x, int size)
{
    for(int i=size-1; i>=0; --i)
        if(*x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void main()
{
    int nr;
    printf("Introduceti un numar intreg: ");
        scanf("%d",&nr), printf("\n");

    if(nr&(1<<2))
        setare_bit(&nr,5);
    else
        resetare_bit(&nr,7);

    print_binar(&nr,sizeof(int)*8);
    printf("Numarul rezultat este: %d\n",nr);
}
