/*
Se citesc 5 coeficienți reali (double) a, b, c, d, e ai funcției: 
f(x) = (ax^2 + 3bx + 6c) / (dx - e) și un număr întreg n. 
Să se afișeze f(n).
*/

#include <stdio.h>
double a, b, c, d, e;

double power(double x, int y)
{
    double aux_x = 1;
    for(int i = 0; i < y; ++i)
        aux_x = aux_x * x;

    return aux_x;
}

double f(int x)
{
    double function;
    function = (a*power(x,2) + 3*b*x + 6*c) / (d*x - e);

    return function;
}

void main()
{
    printf("Introduceti coeficientii functiei:\n");
    printf("f(X) = (aX^2 + 3bX + 6c) / (dX - e)\n");
        printf("a = "), scanf("%lf", &a);
        printf("b = "), scanf("%lf", &b);
        printf("c = "), scanf("%lf", &c);
        printf("d = "), scanf("%lf", &d);
        printf("e = "), scanf("%lf", &e);
    printf("\n");

    int n;
    printf("Introduceti un numar intreg n pentru a calcula f(n):\n");
        printf("n = "), scanf("%d", &n);
    printf("\n");

    printf("f(%d) = %.4lf\n", n, f(n));
}
