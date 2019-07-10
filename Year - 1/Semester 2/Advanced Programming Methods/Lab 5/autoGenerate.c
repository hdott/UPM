#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void autoGenerate(int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", random() % (size+size));
}

int main(int argc, char **argv)
{
    time_t t;
    srand((unsigned) time(&t));

    int size=0, i=0;
    while(i < strlen(argv[1]))
    {
        size *= 10;
        size += argv[1][i++] -'0';
    }

    autoGenerate(size);

    return 0;
}