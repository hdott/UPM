/*
Fie doi vectori de lungimi diferite (n1 şi n2), reprezentând coeficienţii polinoamelor. 
Să se calculeze suma şi produsul celor două polinoame.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define max(a,b) a > b ? a : b

int read_nr_elemente(char s[])
{
    int elem;
    printf("Introduceti numarul de coeficienti al Polinomului %s\n", s);
        printf("coeficienti.%s = ",s), scanf("%d", &elem), system("clear"); 

    return elem;
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

void set_vector_to_0(int V[], int elem)
{
    for(int i = 1; i < elem; ++i)
        V[i] = 0;
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

void suma(int V1[], int V2[], int V3[], int elem1, int elem2)
{
    if(elem1>elem2)
    {
        for(int i = 0; i < elem2; ++i)
            V3[i] = V2[i] + V1[i];
        for(int i = elem2; i < elem1; ++i)
            V3[i] = V1[i];
    }
    else
    {
        for(int i = 0; i < elem1; ++i)
            V3[i] = V1[i] + V2[i];
        for(int i = elem1; i < elem2; ++i)
            V3[i] = V2[i];
    }
}

void produs(int V1[], int V2[], int V3[], int elem1, int elem2)
{
    for(int i = 0; i < elem1; ++i)
        for(int j = 0; j < elem2; ++j)
            V3[i+j] += V1[i] * V2[j];
}

void main()
{
    int P1[MAX], P2[MAX], elemP1, elemP2;

    elemP1 = read_nr_elemente("P1"), system("clear");
        read_vector(P1,elemP1,"P1");
    elemP2 = read_nr_elemente("P2"), system("clear");
        read_vector(P2,elemP2,"P2");
    
    int elem_sum=max(elemP1,elemP2), elem_prod=elemP1+elemP2-1;
    int sum[elem_sum], prod[elem_prod];

    reverse_vector(P1,elemP1);
    reverse_vector(P2,elemP2);
    
    suma(P1,P2,sum,elemP1,elemP2);
    reverse_vector(sum,elem_sum);

    set_vector_to_0(prod,elem_prod);
    produs(P1,P2,prod,elemP1,elemP2);
    reverse_vector(prod,elem_prod);

    reverse_vector(P1,elemP1);
    reverse_vector(P2,elemP2);

    print_vector(P1,elemP1,"P1");
    print_vector(P2,elemP2,"P2");
    print_vector(sum,elem_sum,"Suma(P1,P2)");
    print_vector(prod,elem_prod,"Prod(P1,P2)");
}
