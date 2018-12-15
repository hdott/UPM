/*
Se citește un șir de n numere întregi de la tastatură, apoi un alt număr dat, care se va căuta în acest șir. 
Să se afișeze, dacă există, prima și ultima apariție a acestui număr.
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

void print_vector(int V[], int elem, char s[])
{
    printf("%s este: ", s);
    for(int i = 0; i < elem; ++i)
        printf("%d ", V[i]);
    printf("\n");
}

void check_if_present(int V[], int elem, int x)
{
    int *V1=NULL, *size=NULL, elem1=0;
    for(int i = 0; i < elem; ++i)
        if(x == V[i])
        {
            V1 = (int*) realloc(V1, elem1+1 * sizeof(int));
            V1[elem1++] = i;
        }
    
    print_vector(V,elem,"Sirul initial"), printf("\n");
    if(elem1 == 0)
        printf("Elementul [%d] NU a fost regasit in Sirul initial\n", x);
    else if(elem1 == 1)
        printf("Elementul [%d] a fost gasit o singura data in pozitia %d\n", x, V1[0]+1);
    else if(elem1 > 1)
    {
        printf("Elementul [%d] a fost regasit de %d ori:\n", x, elem1);
        printf("Prima aparitie a sa in pozitia   %d\n", V1[0]+1);
        printf("Ultima aparitie a sa in pozitia: %d\n", V1[elem1-1]+1);
    }

    free(V1);
}

void main()
{
    int elemente, nr;
    read_size(&elemente);

    int *V = (int*) malloc(elemente*sizeof(int));
    read_vector(V,elemente,"Sirului");

    printf("Introduceti un numar pentru a verifica existenta sa in sirul dat:\n");
        printf("nr = "), scanf("%d", &nr), system("clear");

    check_if_present(V,elemente,nr);

    free(V);
}
