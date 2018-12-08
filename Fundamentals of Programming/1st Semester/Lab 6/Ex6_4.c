/*
Se citește un șir de n numere întregi de la tastatură. 
Sa se transforme acest șir de numere în mulțime. 
Fiecare număr care apare inițial de mai multe ori, să apară doar o singură dată în mulțime.
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

void transforma_multime(int V[], int elem)
{
    int elem_bool = maxim(V,elem)+1; 
    int check_bool[elem_bool], multime[MAX], counter=0;
    set_vector_to_0(check_bool,elem_bool);

    for(int i = 0; i < elem; ++i)
        if(!check_bool[V[i]])
        {
            check_bool[V[i]] = 1;
            multime[counter] = V[i], ++counter;
        }

    print_vector(V,elem,"Sirul intial\t");
    print_vector(multime,counter,"Multimea\t");
}

void main()
{
    int V[MAX], elemente;
    
    printf("Introduceti numarul de elemente al sirului:\n");
        printf("elemente = "), scanf("%d", &elemente), system("clear");
        read_vector(V,elemente,"Sirului");

    transforma_multime(V,elemente);
}
