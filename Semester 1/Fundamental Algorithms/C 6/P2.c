/*
Scrieti o functie recursiva, care calculeaza suma elementelor pozitive dintr-un vector
    si produsul elementelor negative.
*/

#include <stdio.h>

int suma_poz_prod_neg(int vector[], int i, int *suma, long long *prod)
{
    printf("[%2d]\t%2d\t%4lld\n",i,*suma,*prod);
    if(i<0)
        return 0;
    else if(vector[i]>0)
    {
        *suma+=vector[i];
        return suma_poz_prod_neg(vector,--i,suma,prod);
    }
    else if(vector[i]<0)
    {
        *prod*=vector[i];
        return suma_poz_prod_neg(vector,--i,suma,prod);
    }
}

void main()
{
    int x[] = {-1,-2,3,4,-5,6,-7,8,-9};
    int suma=0;
    long long prod=1;

    suma_poz_prod_neg(x,sizeof(x)/4-1,&suma,&prod);
    printf("suma = %d\n",suma);
    printf("prod = %lld\n",prod);
}
