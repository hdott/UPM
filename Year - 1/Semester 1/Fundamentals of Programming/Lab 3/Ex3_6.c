/*
Se citesc coeficienții întregi ai unui polinom de gradul 5: 
P(X) = aX^5 + bX^4 + cX^3 + dX^2 + eX + f 

Să se calculeze :
- P(15) 
- P(20) 
- P(2)^P(3)
*/

#include <stdio.h>
int a, b, c, d, e, f;

long long int power(int x, int y)
{
    long long int aux_x = 1;
    for(int i = 0; i < y; ++i)
        aux_x = aux_x * x;

    return aux_x; 
}

long long int P(int x)
{
    long long int polynom;
    polynom = a*power(x,5) + b*power(x,4) + c*power(x,3) + d*power(x,2) + e*x + f;

    return polynom;
}

void main()
{
    printf("Introduceti coeficientii Polinomului:\n");
    printf("P(X) = aX^5 + bX^4 + cX^3 + dX^2 + eX + f\n");
        printf("a = "), scanf("%d", &a);
        printf("b = "), scanf("%d", &b);
        printf("c = "), scanf("%d", &c);
        printf("d = "), scanf("%d", &d);
        printf("e = "), scanf("%d", &e);
        printf("f = "), scanf("%d", &f);
    printf("\n");

    printf("P(15)\t  = %lld\n", P(15));
    printf("P(20)\t  = %lld\n", P(20));
    printf("P(2)^P(3) = %lld\n", power(P(2),P(3)));
}
