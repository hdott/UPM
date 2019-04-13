/* Se dau doua puncte din spatiu oarecare A0(x1,y1,z1) si A1(x2,y2,z2) prin coordonatele
 *  lor reale. Sa se calculeze distanta dintre cele doua puncte. Distanta sa fie
 *  implementata cu ajutorul unui subprogram.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct punctInSpatiu3D
{
    double x;
    double y;
    double z;
} punct;

punct *NewPoint(double x, double y, double z)
{
    punct *newp = malloc(sizeof(punct));

    newp -> x = x;
    newp -> y = y;
    newp -> z = z;

    return newp;
}

double PowerOfTwo(double x)
{
    return (x*x);
}

double FindDistanceBetweenTwoPointsIn3DSpace(double x1, double y1, double z1,
                                            double x2, double y2, double z2)
{
    double tempDistance = PowerOfTwo(x2-x1) + PowerOfTwo(y2-y1) + PowerOfTwo(z2-z1);
    
    return sqrt(tempDistance);
}

int main(void)
{
    double x, y, z;
    punct *A0, *A1;

    printf("Introduceti coordonatele unui punct in Spatiu 3D:\n");
        printf("(x y z): ");
        scanf("%lf %lf %lf", &x, &y, &z);
        A0 = NewPoint(x, y, z);

    printf("\nIntroduceti coordonatele unui al doilea punct in Spatiu 3D:\n");
        printf("(x y z): ");
        scanf("%lf %lf %lf", &x, &y, &z);
        A1 = NewPoint(x, y, z);

    printf("\nDistanta dintre cele doua puncte este: %lf\n",
            FindDistanceBetweenTwoPointsIn3DSpace(A0 -> x, A0 -> y, A0 -> z,
                                                    A1 -> x, A1 -> y, A1 -> z));

    free(A0);
    free(A1);
    return 0;   
}