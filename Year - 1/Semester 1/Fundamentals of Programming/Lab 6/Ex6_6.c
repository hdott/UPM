/*
Fie un şir de n numere întregi să se afişeze numărul de apariţii ale fiecărui element
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define max(a,b) a > b ? a : b

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

void print_aparitii(int V[], int elem)
{ 
    int check_bool[maxim(V,elem)+1], multime[MAX], counter=0;
        set_vector_to_0(check_bool,maxim(V,elem)+1);

    for(int i = 0; i < elem; ++i)
    {
        if(!check_bool[V[i]])
            multime[counter] = V[i], ++counter;
        ++check_bool[V[i]];
    }

    print_vector(V,elem,"Sirul intial"), printf("\n");
        for(int i = 0; i < counter; ++i)
            printf("[%d]\tapare de %d ori\n",multime[i],check_bool[multime[i]]);
}

void main()
{
    int V[MAX], elemente;
    
    printf("Introduceti numarul de elemente al sirului:\n");
        printf("elemente = "), scanf("%d", &elemente), system("clear");
        read_vector(V,elemente,"Sirului");
    
    print_aparitii(V,elemente);
}
