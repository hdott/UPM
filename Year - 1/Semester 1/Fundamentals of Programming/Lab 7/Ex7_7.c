/*
Fie doi vectori de lungimi diferite (n1 şi n2), reprezentând coeficienţii polinoamelor. 
Să se calculeze suma şi produsul celor două polinoame.
*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a > b ? a : b

void read_size(int *elem, char s[])
{
    printf("Introduceti numarul de coeficienti al Polinomului %s\n", s);
        printf("coeficienti.%s = ",s), scanf("%d", elem), system("clear");
}

void read_vector(int V[], int elem, char s[])
{
    printf("Introduceti coeficientii Polinomului %s:\n", s);
    for(int i = 0; i < elem; ++i)
        printf("%s[%d] = ",s,i+1), scanf("%d", &V[i]);
    system("clear");
}

void print_vector(int V[], int elem, char s[])
{
    printf("%s este: ", s);
    for(int i = 0; i < elem; ++i)
        printf("%d ", V[i]);
    printf("\n");
}

void reverse_vector(int V[], int elem)
{
    int j = elem-1;
    for(int i = 0; i < elem/2; ++i && --j)
    {
        int aux = V[i];
        V[i] = V[j];
        V[j] = aux;
    }
}

void suma(int V1[], int V2[], int elem1, int elem2)
{
    int elem_sum=max(elem1,elem2);
    int *sum = (int*) malloc(elem_sum*sizeof(int));
    if(elem1>elem2)
    {
        for(int i = 0; i < elem2; ++i)
            sum[i] = V2[i] + V1[i];
        for(int i = elem2; i < elem1; ++i)
            sum[i] = V1[i];
    }
    else
    {
        for(int i = 0; i < elem1; ++i)
            sum[i] = V1[i] + V2[i];
        for(int i = elem1; i < elem2; ++i)
            sum[i] = V2[i];
    }

    reverse_vector(sum,elem_sum);
    print_vector(sum,elem_sum,"Suma(P1,P2)");
    free(sum);
}

void produs(int V1[], int V2[], int elem1, int elem2)
{
    int elem_prod=elem1+elem2-1;
    int *prod = (int*) malloc(elem_prod*sizeof(int));
    for(int i = 0; i < elem1; ++i)
        for(int j = 0; j < elem2; ++j)
            prod[i+j] += V1[i] * V2[j];

    reverse_vector(prod,elem_prod);
    print_vector(prod,elem_prod,"Prod(P1,P2)");
    free(prod);
}

void main()
{
    int elemP1, elemP2;

    read_size(&elemP1,"P1"), system("clear");
    int *P1 = (int*) malloc(elemP1*sizeof(int));
    read_vector(P1,elemP1,"P1");

    read_size(&elemP2,"P2"), system("clear");
    int *P2 = (int*) malloc(elemP2*sizeof(int));
    read_vector(P2,elemP2,"P2");

    print_vector(P1,elemP1,"P1");
    print_vector(P2,elemP2,"P2"), printf("\n");

    reverse_vector(P1,elemP1);
    reverse_vector(P2,elemP2);
    
    suma(P1,P2,elemP1,elemP2);
    produs(P1,P2,elemP1,elemP2);

    free(P1);
    free(P2);
}
