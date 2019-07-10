/*
Scrieti o functie recursiva care determina maximul elementelor negative ale unui sir de numere intregi.
*/

#include <stdio.h>

int maxim(int sir[], int i, int max)
{
    if(i<0)
        return max;
    else if(max<sir[i]&&sir[i]<0)
        return maxim(sir,--i,max=sir[i]);
    else
        return maxim(sir,--i,max);
}

void main()
{
    int x[]={-10,2,3,-4,5,6,-2,44,-23,43,32,-8};
    int max;

    for(int i=0; i<sizeof(x)/4-1; ++i)
        if(x[i]<0)
        {
            max=x[i];
            break;
        }
    
    printf("Maximul elementelor negative este: %d\n",maxim(x,sizeof(x)/4-1,max));
}
