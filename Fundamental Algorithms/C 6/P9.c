/*
Scrieti o functie recursiva care determina catul si restul impartirii a doua numere intregi.
*/

#include <stdio.h>

int cat_rest(int x, int y, int *cat, int *rest)
{
    if(y>x)
    {
        *rest=x;
        return 0;
    }
    else
    {
        *cat+=1;
        return cat_rest(x-y,y,cat,rest);
    }
}

void main()
{
    int cat=0, rest=0;

    cat_rest(12,5,&cat,&rest);
    printf("%d/%d = %d rest %d\n",12,5,cat,rest);
}
