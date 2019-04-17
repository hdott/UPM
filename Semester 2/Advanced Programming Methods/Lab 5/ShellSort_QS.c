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

void ShellSort_QS(void *base, size_t nmemb, size_t size, 
                        int (*cmp)(const void *, const void *))
{
    void *temp = (void*) malloc(size);

    for(int gap=nmemb/2; gap>0; gap /= 2)
        for(int i=gap, j; i<nmemb; ++i)
        {
            memcpy(temp, base+(i*size), size);

            for(j=i; j>=gap && cmp(base+((j-gap)*size), temp)==1; j-=gap)
                memcpy(base+(j*size), base+((i-gap)*size), size);

            memcpy(base+(j*size), temp, size);
        }

    free(temp);
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
    ShellSort_QS(vector, size, sizeof(vector[0]), Compare);
    printVector(vector, size);

    free(vector);
    return 0;
}