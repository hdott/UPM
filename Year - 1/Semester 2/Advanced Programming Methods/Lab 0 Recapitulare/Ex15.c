// O functie recursiva care genereaza primele n numere Fibonacci

#include <stdio.h>

void FibonacciRecursive(long long unsigned n1, long long unsigned n2, unsigned n)
{
    long long unsigned fib = n1+n2;
    printf("%u ", fib);

    if(n)   return FibonacciRecursive(n2, fib, n-1);
}

int main(void)
{
    long long unsigned n1=1, n2=1;
    unsigned n;

    printf("Introduceti un numar n pentru a afla primele n numere Fibonacci: ");
        scanf("%u", &n);

    printf("\nPrimele %u numere Fibonacii sunt:\n", n);
        printf("%llu %llu ", n1, n2);
        FibonacciRecursive(n1,n2,n-3);
        puts("");

    return 0;
}