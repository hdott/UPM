/*
Să se implementeze un joc de lumini utilizând deplasarea numărului 1 şi Sleep(100) pentru realizarea unei întârzieri. 
Codul de deplasare se va pune într-un ciclu: while(!kbhit()){…}. 
Ex.: 
10000000 
01000000 
00100000 etc.
*/

#include <stdio.h>
#include <unistd.h>

void print_binar(__uint8_t x, int size)
{
    for(int i=size-1; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void roteste_biti_dreapta(__uint8_t *x)
{
    unsigned masca = *x&(1<<0);
    *x >>= 1;
    *x |= masca<<7;
    print_binar(*x,8);
}

void main()
{
    __uint8_t nr=1<<7;

    while(1)
    {
        roteste_biti_dreapta(&nr);
        usleep(55000);
    }
}
