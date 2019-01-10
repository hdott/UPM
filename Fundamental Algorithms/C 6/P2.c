/*
Scrieti o functie recursiva, care calculeaza suma elementelor pozitive dintr-un vector
    si produsul elementelor negative.
*/

#include <stdio.h>

int suma_poz(int vector[], int i, int suma)
{
    if(i<0)
        return suma;
    else if(vector[i]>0)
    {
        printf("[%2d]\t[%2d]\t%2d\n",i,vector[i],suma);
        return suma_poz(vector,--i,suma+vector[i]);
    }
    else
    {
        printf("[%2d]\t[%2d]\t%2d\n",i,vector[i],suma);
        return suma_poz(vector,--i,suma);
    }
}

long long prod_neg(int vector[], int i, long long prod)
{
    if(i<0)
        return prod;
    else if(vector[i]<0)
    {
        printf("[%2d]\t[%2d]\t%4lld\n",i,vector[i],prod);
        return prod_neg(vector,--i,prod*vector[i]);
    }
    else
    {
        printf("[%2d]\t[%2d]\t%4lld\n",i,vector[i],prod);
        return prod_neg(vector,--i,prod);
    }
}

void main()
{
    int x[] = {-1,-2,3,4,-5,6,-7,8,-9};
    
    printf("Suma elementelor pozitive este: %d\n\n",suma_poz(x,sizeof(x)/4-1,0));
    printf("Produsul elementelor negative este: %lld\n",prod_neg(x,sizeof(x)/4-1,1));
}
