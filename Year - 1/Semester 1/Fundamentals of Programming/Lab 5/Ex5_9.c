/*
Să se afișeze valoarea expresiei pentru n și x citit de la tastatură. 
E = 1 + x / 1! + x^2 / 2! + x ^ 3 / 3! + … + x^n / n! 
Să se calculeze diferența E - e^x.
*/

#include <stdio.h>
#include <math.h>

long long int factorial(int x)
{
    long long int rezultat = 1;
    for(int i = 1; i <= x; ++i)
        rezultat *= i;

    return rezultat;
}

void main()
{
    int n, x;

    printf("Introduceti n si x pentru a afla E - e^x\n"); 
    printf("Unde E = 1 + x / 1! + x^2 / 2! + x ^ 3 / 3! + … + x^n / n!\n");
        printf("n = "), scanf("%d", &n);
        printf("x = "), scanf("%d", &x);

    double E = 0;
    
    //loop ce calculeaza E = E + (x^i) / i!
    for(int i = 0; i <= n; ++i)
        E += pow(x,i) / factorial(i);

    printf("\nE - e^x = %lf\n", E-exp(x));
}
