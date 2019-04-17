#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ShellSort(int *vector, int size)
{
    for(int gap=size/2; gap>0; gap /= 2)
    {
        for(int i=gap, j; i<size; ++i)
        {
            int temp = vector[i];
            
            for(j=i; j>=gap && vector[j-gap] > temp; j-=gap)
                vector[j] = vector[i-gap];

            vector[j] = temp;
        }
    }
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
    ShellSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}