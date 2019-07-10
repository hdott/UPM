/*
Sa se defineasca un subprogram care primeste ca parametru un numar naturlal n si
    afiseaza numerele de la 1 la n.
Sa se apeleze aceasta functie de 3 ori cu diferite valori ale lui n.
    (Valorile lui n vor fi citite de la tastatura)
*/

#include <stdio.h>

int read_nr()
{
    int nr;

    puts("Introduceti un numar pentru a afisat toate numerele de la 1-n");
        printf("n = "),scanf("%d", &nr);
    
    return nr;
}

void print_nr(int x)
{
    for(int i=1; i<=x; ++i)
        printf("%d ",i);
    printf("\n\n");
}

void main()
{
    print_nr(read_nr());
    print_nr(read_nr());
    print_nr(read_nr());
}
