/*
Se citește un șir de n numere întregi de la tastatură, să se verifice dacă este simteric.
*/

#include <stdio.h>
#include <stdlib.h>

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

int check_simetrie_vector(int V[], int elem)
{
    int check = 1, j = elem-1;
    for(int i = 0; i < elem/2; ++i && --j)
        if(V[i] != V[j])
        {
            check = 0;
            break;
        }

    return check;
}

void main()
{
    int elemente;
    read_size(&elemente);

    int *V = (int*) malloc(elemente*sizeof(int));
    read_vector(V,elemente,"Sirului");

    if(check_simetrie_vector(V,elemente))
        printf("Sirul introdus este SIMETRIC\n");
    else
        printf("Sirul introdus NU este SIMETRIC\n");

    free(V);
}
