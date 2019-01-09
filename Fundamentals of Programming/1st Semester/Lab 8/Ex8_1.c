#include <stdio.h>

int valoare_bit(__uint8_t x, int poz)
{
    if(x&(1<<poz))
        return 1;
    else
        return 0;
}

int valoare_bit_paritate(__uint8_t x)
{
    int paritate=0;

    for(int i=0; i<8; ++i)
        if(x&(1<<i))
            ++paritate;

    return (paritate%2);
}

int nr_rezultat_dupa_resetare_bit(__uint8_t *x, int poz)
{
    *x &= ~(1<<poz);

    return *x;
}

int nr_rezultat_dupa_setare_bit(__uint8_t *x, int poz)
{
    *x |= 1<<poz;

    return *x; 
}

void main()
{
    __uint8_t nr;
    printf("Introduceti un numar in limita [0,255]: ");
        scanf("%u",&nr), printf("\n");

    printf("Valoarea bitului 3 este: %d\n",valoare_bit(nr,3));
    printf("Valoarea bitului de paritate este: %d\n",valoare_bit_paritate(nr));
    printf("Numarul rezultat după resetarea bitului 2 este: %d\n",nr_rezultat_dupa_resetare_bit(&nr,2));
    printf("Numarul rezultat dupa setarea bitului 4 este: %d\n",nr_rezultat_dupa_setare_bit(&nr,4));
}
