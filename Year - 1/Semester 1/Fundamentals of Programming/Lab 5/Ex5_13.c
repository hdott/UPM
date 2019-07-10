/*
Să se afișeze al n-lea număr prim. 
Numărul întreg n se va genera din intervalul [10, 20].
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random_generate()
{
    unsigned int rand_nr;
    srand((unsigned)time(NULL));
        for(int i = 0; i < 100; ++i)
            for(int j = 0; j < 20; ++j)
                rand_nr = rand() % 10 + 10; //range [10,20]

    return rand_nr;
}

int prime_generator(int x)
{
    int counter = 1;                //variabila pentru a numara numerele prime
    for(int i = 3; ; ++i)
    {
        int j = 2;
        for(j = 2; j <= i-1; ++j)
            if(i % j == 0)          //daca i / j are restul 0 inainte ca i == j
                break;              //inseamna ca numarul nu este prim si iese din loop
        
        if(i == j)                  //daca i == j inseamna ca j a trecut prin toate
            ++counter;              //numerele mai mici decat i si nu a dat restul 0 niciodata
                                    //rezultand ca i este prim
        if(counter == x)
        {
            return i;
            break;
        }
    }
}

void main()
{
    int nr = random_generate();
    printf("Al %d-lea numar prim este: %d\n", nr, prime_generator(nr));
}
