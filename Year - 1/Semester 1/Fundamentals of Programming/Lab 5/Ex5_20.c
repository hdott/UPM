/*
Să se determine numerele de maxim 4 cifre care sunt divizibile atât cu suma cât și cu produsul cifrelor.
*/

#include <stdio.h>
#define MAX 10000

int suma_cifrelor(int x)
{
    int suma;
    for(suma=0 ; x/10 != 0 || x%10 != 0; x = x/10)
        suma += x % 10;

    return suma;
}

int prod_cifrelor(int x)
{
    int prod;
    for(prod = 1; x/10 != 0 || x%10 != 0; x = x/10)
        prod *= x % 10;

    return prod;
}

void print_divizibile()
{
    for(int i = 1; i < MAX; ++i)
    {
        int suma = suma_cifrelor(i);
        int prod = prod_cifrelor(i);
        if(suma == 0 || prod == 0)          //conditie pentru a evita impartirea cu 0
            ;
        else if(i%suma == 0 && i%prod == 0)
            printf("%4d divide suma= %4d & produsul= %4d\n", i, suma, prod);
    }
}

void main()
{
    print_divizibile();
}
