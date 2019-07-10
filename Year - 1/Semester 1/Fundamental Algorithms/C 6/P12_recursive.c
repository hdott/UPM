/*
Inversare numar.
*/

#include <stdio.h>
#include <math.h>

int inversare_numar(int x, int i, int invers)
{
    if(!(x/10)&&!(x%10))
        return invers;
    else
        return inversare_numar(x/10,--i,invers+=(x%10)*pow(10,i));
}

void main()
{
    printf("Inversul lui %d este: %d\n",1234,inversare_numar(1234,sizeof(1234)-1,0));
}
