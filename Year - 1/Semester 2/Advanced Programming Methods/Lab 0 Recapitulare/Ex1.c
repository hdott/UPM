/*
 * Sa se defineasca un subprogram care sa rezolve ecuatia ax^2+bx+c=0 (de gradul II).
 *  Se va apela de 3 ori cu diferiti coeficienti a,b,c;
 */

#include <stdio.h>
#include <math.h>
#define REPETITII 3

void quadratic_eq(int a, int b, int c); // function prototype

int main(void)
{
    int a, b, c;

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti coeficientii unei ecuatii de gradul II: ");
            scanf("%d%d%d",&a, &b, &c);
        quadratic_eq(a,b,c);
    }

    return 0;
}

// computes solutions of the quadratic formula
void quadratic_eq(int a, int b, int c)
{
    int D = (b*b) - 4*a*c;  // delta = b^2 - 4ac
    int state;

    if(D > 0)
        state = 1;
    else if(D == 0)
        state = 2;
    else
        state = 3;

    switch(state)
    {
        case 1:
            printf("Solutiile ecuatiei sunt:\n");
                printf("x1 = %+lf\n",(-b+sqrt(D)) / (2.0*a));
                printf("x2 = %+lf\n",(-b-sqrt(D)) / (2.0*a));
            break;
        case 2:
            printf("Solutiile ecuatiei sunt egale:\n");
                printf("x1 = x2 = %+lf\n",(-b)/(2.0*a));
            break;
        case 3:
            printf("Solutiile ecuatiei sunt complexe:\n");
                printf("Partea Reala este: \t%+lf\n", (-b) / (2.0*a));
                printf("Partea Imaginara este: \t%+lf i\n", sqrt(-D) / (2.0*a));
            break;
    }
}