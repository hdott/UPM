/*
Se citește un șir de n numere întregi de la tastatură. 
Sa se transforme acest șir de numere în mulțime. 
Fiecare număr care apare inițial de mai multe ori, să apară doar o singură dată în mulțime.
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

void transforma_multime(int V[], int elem)
{
    int elem_bool = maxim(V,elem)+1, counter=0;
    int *multime=NULL;

    int *check_bool = (int*) calloc(elem_bool, sizeof(int));

    for(int i = 0; i < elem; ++i)
        if(!check_bool[V[i]])
        {
            multime = (int*) realloc(multime, (counter+1) * sizeof(int));
            check_bool[V[i]] = 1;
            multime[counter++] = V[i];
        }

    print_vector(V,elem,"Sirul intial\t");
    print_vector(multime,counter,"Multimea\t");

    free(V);
    free(check_bool);
    free(multime);
}

void main()
{
    int elemente;
    read_size(&elemente);

    int *V = (int*) malloc(elemente*sizeof(int));
    read_vector(V,elemente,"Sirului");

    transforma_multime(V,elemente);
}
