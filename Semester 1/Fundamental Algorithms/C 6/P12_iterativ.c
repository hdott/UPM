/*
Inversare numar.
*/

#include <stdio.h>
#include <math.h>

int inversare_numar(int x)
{
    int v[10];
    int invers=0, counter=-1;

    for(; x/10||x%10; x/=10)
        v[++counter]=x%10;

    for(int i=0; counter>=0;++i,--counter)
        invers+=v[counter]*pow(10,i);

    return invers;
}

void main()
{
    printf("Inversul lui %d este: %d\n",1234,inversare_numar(1234));
}
