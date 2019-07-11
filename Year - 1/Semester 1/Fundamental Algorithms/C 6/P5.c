/*
Scrieti o functie recursiva care determina maximum elementelor unui sir de numere intregi.
*/

#include <stdio.h>

int maxim(int sir[], int i, int max)
{
    if(i<0)
        return max;
    else if(max<sir[i])
        return maxim(sir,--i,max=sir[i]);
    else
        return maxim(sir,--i,max);
}

void main()
{
    int x[]={-1,2,3,-4,5,6,-2,44,-23,43,32,-8};
    
    printf("Maximul sirului este: %d\n",maxim(x,sizeof(x)/4-1,x[0]));
}
