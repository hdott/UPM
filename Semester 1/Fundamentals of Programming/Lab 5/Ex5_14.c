/*
Să se afișeze al n-lea număr Fibonacci. n se va citi de la tastatură.
*/

#include <stdio.h>

int nth_Fibonacci(int x)
{
    int counter = 0, fib_anterior = 0, fib = 1, aux;

    for(int i = 1; i < x; ++i)
    {
        aux = fib;
        fib += fib_anterior;
        fib_anterior = aux;
    }

    return fib;
}

void main()
{
    int n;

    printf("Introduceti un numar natural:\n");
        printf("n = "), scanf("%d", &n);

    printf("\nAl %d-lea numar Fibonacci este: %d\n", n, nth_Fibonacci(n));
}
