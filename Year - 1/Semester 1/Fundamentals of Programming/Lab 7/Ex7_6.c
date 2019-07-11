/*
Fie un şir de n numere întregi să se afişeze numărul de apariţii ale fiecărui element
*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a > b ? a : b

void read_size(int *elem)
{
    printf("Introduceti numarul de elemente al sirului:\n");
        printf("elemente = "), scanf("%d", elem), system("clear");
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

void print_aparitii(int V[], int elem)
{ 
    int elem_bool = maxim(V,elem)+1, counter=0;
    int *multime=NULL;

    int *check_bool = (int*) calloc(elem_bool, sizeof(int));

    for(int i = 0; i < elem; ++i)
    {
        if(!check_bool[V[i]])
        {
            multime = (int*) realloc(multime, (counter+1) * sizeof(int));
            multime[counter++] = V[i];
        }
        ++check_bool[V[i]];
    }

    print_vector(V,elem,"Sirul intial"), printf("\n");
        for(int i = 0; i < counter; ++i)
            printf("[%d]\tapare de %d ori\n",multime[i],check_bool[multime[i]]);
    
    free(V);
    free(check_bool);
    free(multime);
}

void main()
{
    int elemente, nr;
    read_size(&elemente);

    int *V = (int*) malloc(elemente*sizeof(int));
    read_vector(V,elemente,"Sirului");
    
    print_aparitii(V,elemente);
}
