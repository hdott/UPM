/*
Să se afișeze suma cifrelor unui număr generat în intervalul [0, 1000000]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_generate()
{
    unsigned int rand_nr;
    srand((unsigned)time(NULL));
        for(int i = 0; i < 100; ++i)
            for(int j = 0; j < 20; ++j)
                rand_nr = rand() % 100000 + 1;

    return rand_nr;
}

long long int suma_cifrelor(int x)
{
    long long int sum = 0;
    while(x / 10 != 0 || x % 10 != 0)
    {
        sum += x%10;
        x = x / 10;
    }

    return sum;
}

void main()
{
    int nr = random_generate();
    printf("Suma cifrelor numarului [%d] este = %lld\n", nr, suma_cifrelor(nr));
}
