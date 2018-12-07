/*
Să se calculeze răsturnatul unui număr generat din [5000, 9999].
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
                rand_nr = rand() % 4999 + 5000; //range [5000,9999]

    return rand_nr;
}

int rastoarna_nr(int x)
{
    int rasturnat = 0;
    for(int i = 1000; x/10 != 0 || x%10 != 0; i = i/10)
    {
        rasturnat += (x%10) * i;
        x = x / 10;
    }
    
    return rasturnat;
}

void main()
{
    int nr = random_generate();
    printf("Rasturnatul numarului [%d] este: [%d]\n", nr, rastoarna_nr(nr));
}
