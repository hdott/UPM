/* Sa se creeze un tip Punct2D, avand 2 campuri abscisa(x) si ordonata(y) unui plan.
 * - Sa se citeasca 3 puncte de la tastatura, si sa calculeze distanta intre oricare
 *      doua puncte.
 * - Sa se afiseze centrul de greutate al punctelor.
 * - Sa se citeasca varfurile unui poligon de N laturi (N+1) varfuri. Sa se afiseze
 *      centrul de greutate al acestor puncte.
 * - Sa se ordoneze punctele dupa abscisa, iar in caz de egalitate si dupa ordonata.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Punct2D
{
    double x;
    double y;
} Punct2D;

Punct2D *NewPoint(double x, double y)
{
    Punct2D *newp = malloc(sizeof(Punct2D));

    newp -> x = x;
    newp -> y = y;

    return newp;
}

double PowerOfTwo(double x)
{
    return (x*x);
}

double FindDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double tempDistance = PowerOfTwo(x2-x1) + PowerOfTwo(y2-y1);

    return sqrt(tempDistance);
}

void FreeVectorOfStruct(Punct2D **vector, int size)
{
    for(int i=0; i<size; ++i)
        free(*(vector+i));
    free(vector);
}

void FindCenterOfMass(Punct2D **vector, double *x, double *y, int size)
{
    double tempCoM_x = (*(vector+0)) -> x;
    double tempCoM_y = (*(vector+0)) -> y;

    for(int i=1; i<size; ++i)
        tempCoM_x += (*(vector+i)) -> x;

    for(int i=1; i<size; ++i)
        tempCoM_y += (*(vector+i)) -> y;

    *x = tempCoM_x / (double) size;
    *y = tempCoM_y / (double) size;
}

void SortPoints(Punct2D **vector, int size)
{
    Punct2D *temp = NULL;

    for(int i=0; i<size-1; ++i)
        for(int j=i+1; j<size; ++j)
        {
            if((*(vector+i)) -> x > (*(vector+j)) -> x)
            {
                temp = *(vector+i);
                *(vector+i) = *(vector+j);
                *(vector+j) = temp;
                continue;
            } 

            if((*(vector+i)) -> x == (*(vector+j)) -> x)
                if((*(vector+i)) -> y > (*(vector+j)) -> y)
                {
                    temp = *(vector+i);
                    *(vector+i) = *(vector+j);
                    *(vector+j) = temp;
                } 
        }
}

void PrintVectorOfPoints(Punct2D **vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("[%d](%.2lf,%.2lf)\n", i, (*(vector+i)) -> x, (*(vector+i)) -> y);
}

int main(void)
{
    // Sa se citeasca 3 puncte de la tastatura si sa se calculeze distanta
    //  intre oricare doua puncte.
    int size = 3;
    Punct2D **vectorPuncte = malloc(sizeof(Punct2D)*size);
    double x, y;

    printf("Introduceti 3 puncte de coordonate:\n");
        printf("(x y): "), scanf("%lf %lf", &x, &y);
        *(vectorPuncte+0) = NewPoint(x, y);
        printf("(x y): "), scanf("%lf %lf", &x, &y);
        *(vectorPuncte+1) = NewPoint(x, y);
        printf("(x y): "), scanf("%lf %lf", &x, &y);
        *(vectorPuncte+2) = NewPoint(x, y);

    printf("Distanta intre punctele (%.2lf,%.2lf) si (%.2lf,%.2lf) este: %.4lf\n",
                                        (*(vectorPuncte+0)) -> x, (*(vectorPuncte+0)) -> y,
                                        (*(vectorPuncte+1)) -> x, (*(vectorPuncte+1)) -> y,
            FindDistanceBetweenTwoPoints((*(vectorPuncte+0)) -> x, (*(vectorPuncte+0)) -> y,
                                        (*(vectorPuncte+1)) -> x, (*(vectorPuncte+1)) -> y));

    printf("Distanta intre punctele (%.2lf,%.2lf) si (%.2lf,%.2lf) este: %.4lf\n",
                                        (*(vectorPuncte+0)) -> x, (*(vectorPuncte+0)) -> y,
                                        (*(vectorPuncte+2)) -> x, (*(vectorPuncte+2)) -> y,
            FindDistanceBetweenTwoPoints((*(vectorPuncte+0)) -> x, (*(vectorPuncte+0)) -> y,
                                        (*(vectorPuncte+2)) -> x, (*(vectorPuncte+2)) -> y));

    printf("Distanta intre punctele (%.2lf,%.2lf) si (%.2lf,%.2lf) este: %.4lf\n",
                                        (*(vectorPuncte+1)) -> x, (*(vectorPuncte+1)) -> y,
                                        (*(vectorPuncte+2)) -> x, (*(vectorPuncte+2)) -> y,
            FindDistanceBetweenTwoPoints((*(vectorPuncte+1)) -> x, (*(vectorPuncte+1)) -> y,
                                        (*(vectorPuncte+2)) -> x, (*(vectorPuncte+2)) -> y));
    
    // Sa se afiseze centrul de greutate al punctelor
    FindCenterOfMass(vectorPuncte, &x, &y, size);
    printf("\nCentrul de Greutate al punctelor este: CG(%.2lf,%.2lf)\n", x, y);
    
    FreeVectorOfStruct(vectorPuncte, size);

    // Sa se citeasca varfurile unui poligon de N laturi (N+1) varfuri.
    int sides;
    printf("\nIntroduceti numarul de laturi al unui poligon: ");
        scanf("%d", &sides);
        ++sides;
        
    vectorPuncte = malloc(sizeof(Punct2D)*sides);

    printf("\nIntroduceti coordonatele punctelor(varfurilor) poligonului:\n");
    for(int i=0; i<sides; ++i)
    {
        printf("[%d](x y): ", i+1), scanf("%lf %lf", &x, &y);
        *(vectorPuncte+i) = NewPoint(x, y);
    }

    // Sa se afiseze centrul de greutate al acestor puncte;
    FindCenterOfMass(vectorPuncte, &x, &y, sides);
    printf("\nCentrul de Greutate al punctelor(varfurilor) Poligonului este:\n");
        printf("CG(%.2lf,%.2lf)\n", x, y);

    // Sa se ordoneze punctele duba abscisa, iar in caz de egalitate dupa ordonata
    SortPoints(vectorPuncte, sides);
    printf("\nVectorul ordonat este:\n");
    PrintVectorOfPoints(vectorPuncte, sides);


    FreeVectorOfStruct(vectorPuncte, sides);
    return 0;
}