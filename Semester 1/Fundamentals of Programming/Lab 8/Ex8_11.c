/*
Se consideră un set de 8 LED-uri legat la portull paralel. Să se implementeze un program care realizează un joc de leduri ce permite aprinderea concomitentă a două leduri şi "deplasarea" acestora în sens invers. 
Programul va utiliza o întârziere introdusă de la tastatură. 
Ex.: 
10000001 
01000010 
00100100 
…
*/

#include <stdio.h>
#include <unistd.h>
#define multiplu 100000

void print_binar(__uint8_t x, int size)
{
    for(int i=size-1; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\n");
}

void joc_de_lumini(__uint8_t *x, float delay)
{
    int start = *x;
    
    for(__uint8_t masca1=1<<7,masca2=1; ; masca1>>=1,masca2<<=1)
    {
        if(!masca1||!masca2)
        {
            masca1=1<<7;
            masca2=1;
        }
        print_binar(masca1|masca2,sizeof(__uint8_t)*8);
        usleep(delay*multiplu);
    }
}

void main()
{
    __uint8_t nr=(1<<7)|(1<<0);
    float delay;
    printf("Introduceti valoarea intarzierii in secunde: ");
        scanf("%f",&delay);
    
    joc_de_lumini(&nr,delay);
}
