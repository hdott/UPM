/*
Se citesc două numere naturale de la tastatură, n şi m. n este stocat pe 32 de biţi, iar m este stocat pe 8 biţi. 
Să se modifice starea bitului al m-lea pe 1 şi starea bitului al 32-m-lea pe 0.
*/

#include <stdio.h>

void resetare_bit(__uint32_t *x, __uint8_t poz)
{
    *x&=~(1<<poz);
}

void setare_bit(__uint32_t *x, __uint8_t poz)
{
    *x|=(1<<poz);
}

void print_binar(__uint32_t x, int size)
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
    __uint8_t m;
    __uint32_t n;
    
    printf("Introduceti un numar in limita [0,%u]: ",__UINT32_MAX__);
        scanf("%u",&n);
    printf("Introduceti un numar in limita [0,%u]: ",__UINT8_MAX__);
        scanf("%u",&m),printf("\n");

    setare_bit(&n,m);
    resetare_bit(&n,32-m);
    print_binar(n,sizeof(__uint32_t)*8);

    printf("Numarul rezultat este: %u\n",n);
}
