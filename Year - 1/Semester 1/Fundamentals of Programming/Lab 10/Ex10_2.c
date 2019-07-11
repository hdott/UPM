/*
Sa se defineasca un subprogram care primeste un numar natural n si afiseaza primii
    n termeni din sirul lui Fibonacci.
Sa se apeleze aceasta functie de 4 ori cu diferite valori ale lui n.
    (Valorile lui n vor fi citite de la tastatura)
*/

#include <stdio.h>

int read_nr()
{
    int nr;

    puts("Introduceti un numar pentru a afisat toate numerele Fibonacci de la 1-n");
        printf("n = "),scanf("%d", &nr);
    
    return nr;
}

void print_fib(int n)
{
    int x=0, y=1, suma=0;
    printf("%d ", y);

    for(int i=1; i<n; ++i)
    {
        printf("%d ",suma=x+y);
        x = y;
        y = suma;
    }
    printf("\n\n");
}

void main()
{
    print_fib(read_nr());
    print_fib(read_nr());
    print_fib(read_nr());
    print_fib(read_nr());
}
