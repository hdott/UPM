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

void CocktailSort_QS(void *base, size_t nmemb, size_t size, 
                        int (*cmp)(const void *, const void *))
{
    void *aux = (void*) malloc(size);
    _Bool swapped = 1;
    int start = 0;
    int end = nmemb;

    while(swapped)
    {
        swapped = 0;

        for(int i=start; i<nmemb-1; ++i)
            if(cmp(base+(i*size), base+((i+1)*size)) == 1)
            {
                memcpy(aux, base+(i*size), size);
                memcpy(base+(i*size), base+((i+1)*size), size);
                memcpy(base+((i+1)*size), aux, size);
                swapped = 1;
            }

        if(!swapped)    break;

        swapped = 0;
        end--;

        for(int i=end-1; i>=start; --i)
            if(cmp(base+(i*size), base+((i+1)*size)) == 1)
            {
                memcpy(aux, base+(i*size), size);
                memcpy(base+(i*size), base+((i+1)*size), size);
                memcpy(base+((i+1)*size), aux, size);
                swapped = 1;
            }

        start++;
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
    CocktailSort_QS(vector, size, sizeof(vector[0]), Compare);
    printVector(vector, size);

    free(vector);
    return 0;
}