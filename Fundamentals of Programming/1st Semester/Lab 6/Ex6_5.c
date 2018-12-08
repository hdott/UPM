/*
Se dau două mulțimi în câte un vector de numere întregi. 
Să se calculeze reuniunea, intersecția și diferența lor: A - B și B - A.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define max(a,b) a > b ? a : b

int read_nr_elemente(char s)
{
    int elem;
    printf("Introduceti numarul de elemente al Multimii %c\n", s);
        printf("elem%c = ",s), scanf("%d", &elem), system("clear"); 

    return elem;
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

void set_vector_to_0(int V[], int elem)
{
    for(int i = 1; i < elem; ++i)
        V[i] = 0;
}

void reuniune(int V1[], int V2[], int elem1, int elem2)
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = max(max1,max2)+1;
    int check_bool[elem_bool], reuniune[MAX], counter=0;
        set_vector_to_0(check_bool,elem_bool);
    
    for(int i = 0; i < elem1; ++i)                  //transforma check[element] in 1 cand intalneste un element
        if(!check_bool[V1[i]])                      //nou si salveaza elementul in reuniune[]
        {                                           //daca elementul e gasit a doua oara nu este salvat in reuniune[]
            check_bool[V1[i]] = 1;
            reuniune[counter] = V1[i], ++counter;
        }
    for(int i = 0; i < elem2; ++i)                  //idem pentru multimea 2
        if(!check_bool[V2[i]])
        {
            check_bool[V2[i]] = 1;
            reuniune[counter] = V2[i], ++counter;
        }

    print_vector(reuniune,counter,"Reuniune(A,B)\t");
}

void intersectie(int V1[], int V2[], int elem1, int elem2)
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = max(max1,max2)+1;
    int check_bool[elem_bool], intersectie[MAX], counter=0;
        set_vector_to_0(check_bool,elem_bool);
    
    for(int i = 0; i < elem1; ++i)          //transforma check[element] in 1 cand intalneste un element nou
        if(!check_bool[V1[i]])
            check_bool[V1[i]] = 1;
    for(int i = 0; i < elem2; ++i)          //daca check[element] e 1 cand intalneste un element din multimea 2
        if(check_bool[V2[i]])               //il salveaza in intersectie[]
            intersectie[counter] = V2[i], ++counter;

    print_vector(intersectie,counter,"Intersectie(A,B)");
}

void diferenta(int V1[], int V2[], int elem1, int elem2)
{
    int max1=maxim(V1,elem1), max2=maxim(V2,elem2);
    int elem_bool = max(max1,max2)+1;
    int check_bool[elem_bool], diferenta[MAX], counter=0;
        set_vector_to_0(check_bool,elem_bool);
    
    for(int i = 0; i < elem2; ++i)          //transforma check[element] in 1 cand intalneste un element nou din multimea 2
        if(!check_bool[V2[i]])
            check_bool[V2[i]] = 1;
    for(int i = 0; i < elem1; ++i)          //daca check[element] e 0 cand intalneste un element din multimea 1
        if(!check_bool[V1[i]])              //inseamna ca acesta nu se afla in multimea 1 si e salvat in difierenta[]
            diferenta[counter] = V1[i], ++counter;

    print_vector(diferenta,counter,"Diferenta(A,B)\t");
}

void main()
{
    int A[MAX], B[MAX], elem_A, elem_B;

    elem_A = read_nr_elemente('A');
        read_vector(A,elem_A,"Multimii A");
    elem_B = read_nr_elemente('B');
        read_vector(B,elem_B,"Multimii B");

    print_vector(A,elem_A,"Multimea A");
    print_vector(B,elem_B,"Multimea B"), printf("\n");
        reuniune(A,B,elem_A,elem_B);
        intersectie(A,B,elem_A,elem_B);
        diferenta(A,B,elem_A,elem_B);
        diferenta(B,A,elem_B,elem_A);
}
