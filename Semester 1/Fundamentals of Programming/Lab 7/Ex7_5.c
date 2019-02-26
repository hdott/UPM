/*
Se dau două mulțimi în câte un vector de numere întregi. 
Să se calculeze reuniunea, intersecția și diferența lor: A - B și B - A.
*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a > b ? a : b

void read_size(int *elem, char s)
{
    printf("Introduceti numarul de elemente al Multimii %c\n", s);
        printf("elem%c = ",s), scanf("%d", elem), system("clear"); 
}

void read_vector(int V[], int elem, char s[])
{
    printf("Introduceti elementele %s:\n", s);
    for(int i = 0; i < elem; ++i)
        printf("V[%d] = ", i+1), scanf("%d", &V[i]);
    system("clear");
}

void print_vector(int V[], int elem, char s[])
{
    printf("%s este: ", s);
    for(int i = 0; i < elem; ++i)
        printf("%d ", V[i]);
    printf("\n");
}

int maxim(int V[], int elem)
{
    int maxim = V[0];
    for(int i = 1; i < elem; ++i)
        maxim = max(maxim, V[i]);

    return maxim;
}

void reuniune(int V1[], int V2[], int elem1, int elem2)
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = max(max1,max2)+1;
    int *reuniune=NULL, counter=0;

    int *check_bool = (int*) calloc(elem_bool, sizeof(int));
    
    for(int i = 0; i < elem1; ++i)                  //transforma check[element] in 1 cand intalneste un element
        if(!check_bool[V1[i]])                      //nou si salveaza elementul in reuniune[]
        {                                           //daca elementul e gasit a doua oara nu este salvat in reuniune[]
            reuniune = (int*) realloc(reuniune, (counter+1)*sizeof(int));
            check_bool[V1[i]] = 1;
            reuniune[counter++] = V1[i];
        }
    for(int i = 0; i < elem2; ++i)                  //idem pentru multimea 2
        if(!check_bool[V2[i]])
        {
            reuniune = (int*) realloc(reuniune, (counter+1)*sizeof(int));
            check_bool[V2[i]] = 1;
            reuniune[counter++] = V2[i];
        }

    print_vector(reuniune,counter,"Reuniune(A,B)\t");
    free(check_bool);
    free(reuniune);
}

void intersectie(int V1[], int V2[], int elem1, int elem2)
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = max(max1,max2)+1;
    int *intersectie=NULL, counter=0;

    int *check_bool = (int*) calloc(elem_bool, sizeof(int));
    
    for(int i = 0; i < elem1; ++i)          //transforma check[element] in 1 cand intalneste un element nou
        if(!check_bool[V1[i]])
            check_bool[V1[i]] = 1;
    for(int i = 0; i < elem2; ++i)          //daca check[element] e 1 cand intalneste un element din multimea 2
        if(check_bool[V2[i]])               //il salveaza in intersectie[]
        {
            intersectie = (int*) realloc(intersectie, (counter+1)*sizeof(int));
            intersectie[counter++] = V2[i];
        }

    print_vector(intersectie,counter,"Intersectie(A,B)");
    free(check_bool);
    free(intersectie);
}

void diferenta(int V1[], int V2[], int elem1, int elem2, char s[])
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = (max(max1,max2))+1;
    int *diferenta=NULL, counter=0;

    int *check_bool = (int*) calloc(elem_bool, sizeof(int));
    
    for(int i = 0; i < elem2; ++i)          //transforma check[element] in 1 cand intalneste un element nou din multimea 2
        if(!check_bool[V2[i]])
            check_bool[V2[i]] = 1;
    for(int i = 0; i < elem1; ++i)          //daca check[element] e 0 cand intalneste un element din multimea 1
        if(!check_bool[V1[i]])              //inseamna ca acesta nu se afla in multimea 1 si e salvat in difierenta[]
        {
            diferenta = (int*) realloc(diferenta, (counter+1)*sizeof(int));
            diferenta[counter++] = V1[i];
        }
    
    print_vector(diferenta,counter,s);
    free(check_bool);
    free(diferenta);
}

void main()
{
    int elem_A, elem_B;

    read_size(&elem_A,'A');
        int *A = (int*) malloc(elem_A * sizeof(int));
        read_vector(A,elem_A,"Multimii A");
    read_size(&elem_B,'B');
        int *B = (int*) malloc(elem_B * sizeof(int));
        read_vector(B,elem_B,"Multimii B");

    print_vector(A,elem_A,"Multimea A");
    print_vector(B,elem_B,"Multimea B"), printf("\n");
        reuniune(A,B,elem_A,elem_B);
        intersectie(A,B,elem_A,elem_B);
        diferenta(A,B,elem_A,elem_B,"Diferenta(A,B)\t");
        diferenta(B,A,elem_B,elem_A,"Diferenta(B,A)\t");
    
    free(A);
    free(B);
}
