/* Sa se scrie o functie cu numar variabil de argumente, primul parametru este
 *  cel fix (n - contorul numerelor); si le afiseaza in ordine crescatoare
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int Compare(const void *a, const void *b)
{
    int *A = (int*)a;
    int *B = (int*)b;

    if(*A > *B)     return 1;
    if(*A < *B)     return -1;
    if(*A == *B)    return 0;
}

void Order(int n, ...)
{
    int vector[n];
    va_list list;
    va_start(list, n);

    for(int i=0; i<n; ++i)
        vector[i] = va_arg(list, int);

    qsort(vector, n, sizeof(int), Compare);

    printf("Ordered:\n");
    for(int i=0; i<n; ++i)  printf("%d ", vector[i]);
    puts("");

    va_end(list);
}

int main(void)
{
    Order(4, 5, 8, 2, 4);

    return 0;
}