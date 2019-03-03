/*
 * Sa se defineasca un subprogram care primeste ca pramateru un numar real n
 *  reprezentand latura unui patrat si returneaza aria patratului. Afisarea
 *  rezultatului se va face in programul principal. Sa se apeleze aceasta 
 *  functie de 3 ori cu diferite valori ale lui n. (Valorile lui n vor functie
 *  citite de la tastatura)
 */

#include <stdio.h>
#define REPETITII 3

double area_of_sqare(double n); // function prototype

int main(void)
{
    double n;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un numar real: ");
            scanf("%lf",&n);
        printf("Aria unui patrat cu latura (=%.4lf) este: %lf\n",
                n,area_of_sqare(n));
    }

    return 0;
}

// returns the area of a square
double area_of_sqare(double n)
{
    return n*n;
}