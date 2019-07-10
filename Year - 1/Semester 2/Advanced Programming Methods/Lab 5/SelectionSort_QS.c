#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Compare(const void *a, const void *b)
{
    const int *x = (const int*) a;
    const int *y = (const int*) b;

    if(*x > *y) return 1;
    if(*x < *y) return -1;

    return 0;
}

void SelectionSort_QS(void *base, size_t nmemb, size_t size, 
                        int (*cmp)(const void *, const void *))
{
    void *aux = (void*) malloc(size);

    for(int i=0; i<nmemb-1; ++i)
    {
        int minI = i;

        for(int j=i+1; j<nmemb; ++j)
            if(cmp(base+(j*size), base+(minI*size)) == -1)
                minI = j;

        memcpy(aux, base+(minI*size), size);
        memcpy(base+(minI*size), base+(i*size), size);
        memcpy(base+(i*size), aux, size);
    }

    free(aux);
}

void printVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(int argc, char **argv)
{
    int size = argc-1;

    int *vector = (int*) calloc(size, sizeof(int));

    for(int i=1, index=0; i<argc; ++i, ++index)
        for(int j=0; j<strlen(argv[i]); ++j)
        {
            vector[index] *= 10;
            vector[index] += argv[i][j] - '0';
        }

    printVector(vector, size);
    SelectionSort_QS(vector, size, sizeof(vector[0]), Compare);
    printVector(vector, size);

    free(vector);
    return 0;
}