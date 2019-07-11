#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "meniu.h"
#define MAX 5
#define KB 1000


typedef struct imagine
{
    unsigned nrOcteti;
    __uint8_t *secventa;
    __int64_t sumaDeControl;
} IMAGE;

static IMAGE vector[MAX];

static unsigned head = 0;
static int tail = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    ControlMeniu(2, 1);
}

static unsigned GenerateRandom(unsigned nr1, unsigned nr2)
{
    time_t t;
    srand((unsigned) time(&t));

    return rand() % nr1 + nr2;
}

static void Enqueue()
{
    

    if(tail == MAX-1)
    {
        printf("\nQueue Overflow!\n");

        ReturnToPrev();
    }
    else
    {
        ++tail;
        
        vector[tail].nrOcteti = GenerateRandom(90, 10);

        int size = vector[tail].nrOcteti * KB;
        vector[tail].secventa = malloc(size);

        for(int i=0; i<size; ++i)
            *(vector[tail].secventa + i) = GenerateRandom(255, 0);

        vector[tail].sumaDeControl = 0;
        for(int i=0; i<size; ++i)
            vector[tail].sumaDeControl += *(vector[tail].secventa + i);

        printf("\nElementul a fost adaugat cu Succes!\n");
    }
}

static void Dequeue()
{
    if(tail == -1)
    {
        printf("\nQueue Underflow!\n");

        ReturnToPrev();
    }
    else
    {
        printf("\nsuma de control -> %d\n", vector[head].sumaDeControl);

        int size = vector[head].nrOcteti * KB;
        __int64_t temp = 0;
        
        for(int i=0; i<size; ++i)
            temp += *(vector[head].secventa + i);

        if(temp ==  vector[head].sumaDeControl)
            printf("Suma a fost verificata si este Corecta!\n");
        else
            printf("Suma a fost verificata si Nu este Corecta!\n");

        free(vector[head].secventa);

        for(int i=0; i<tail; ++i)
            vector[i] = vector[i+1];
        
        --tail;
    }
}

static void Clear()
{
    if(tail == -1)
    {
        printf("\nQueue is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        for( ; tail>=0; --tail)
        {
            printf("\nsuma de control -> %d\n", vector[head].sumaDeControl);

            free(vector[head].secventa);
            
            for(int i=0; i<tail; ++i)
                vector[i] = vector[i+1];

        }
    }
}

void ControlCoadaStaticaOE(int option)
{
    switch (option)
    {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Clear();
            break;
        default:
            printf("\nSomething went Wrong with ControlCoadaStaticaOE!\n");
            break;
    }
}