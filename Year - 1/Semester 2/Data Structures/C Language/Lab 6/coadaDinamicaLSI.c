#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "meniu.h"
#define KB 1000

typedef struct imagine
{
    unsigned nrOcteti;
    __uint8_t *secventa;
    __int64_t sumaDeControl;
    struct imagine *next;
} IMAGE;

static IMAGE *head = NULL;
static IMAGE *tail = NULL;

static unsigned GenerateRandom(unsigned nr1, unsigned nr2)
{
    time_t t;
    srand((unsigned) time(&t));

    return rand() % nr1 + nr2;
}

static IMAGE *NewElement()
{
    srand(time(NULL));

    IMAGE *newp = (IMAGE*) malloc(sizeof(IMAGE));

    newp -> nrOcteti = GenerateRandom(90, 10);

    int size = newp -> nrOcteti * KB;
        newp -> secventa = malloc(size);

    for(int i=0; i<size; ++i)
        *(newp -> secventa + i) = GenerateRandom(255, 0);

    newp -> sumaDeControl = 0;
    for(int i=0; i<size; ++i)
        newp -> sumaDeControl += *(newp -> secventa + i);

    newp -> next = NULL;

    return newp;
}


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    ControlMeniu(2, 2);
}

static void Enqueue()
{
    IMAGE *newp = NewElement();
    IMAGE **tracer = &tail;

    if(!(*tracer))
    {
        *tracer = newp;
        head = newp;

        printf("\nElementul a fost adaugat cu Succes!\n");
    }
    else
    {
        (*tracer) -> next = newp;
        *tracer = newp;

        printf("\nElementul a fost adaugat cu Succes!\n");
    }
}

static void Dequeue()
{
    IMAGE *_toRemove = NULL;
    IMAGE **tracer = &head;

    if(!(*tracer))
    {
        printf("\nQueue Underflow!\n");

        ReturnToPrev();
    }
    else if(*tracer == tail)
    {
        printf("\nsuma de control -> %d\n", (*tracer) -> sumaDeControl);

        int size = (*tracer) -> nrOcteti * KB;
        __int64_t temp = 0;

        for(int i=0; i<size; ++i)
            temp += *((*tracer) -> secventa + i);

        if(temp == (*tracer) -> sumaDeControl)
            printf("Suma a fost verificata si este Corecta!\n");
        else
            printf("Suma a fost verificata si Nu este Corecta!\n");


        _toRemove = *tracer;

        free(_toRemove -> secventa);
        free(_toRemove);

        *tracer = NULL;
        tail = NULL;
    }
    else
    {
        printf("\nsuma de control -> %d\n", (*tracer) -> sumaDeControl);

        int size = (*tracer) -> nrOcteti * KB;
        __int64_t temp = 0;

        for(int i=0; i<size; ++i)
            temp += *((*tracer) -> secventa + i);

        if(temp == (*tracer) -> sumaDeControl)
            printf("Suma a fost verificata si este Corecta!\n");
        else
            printf("Suma a fost verificata si Nu este Corecta!\n");


        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove -> secventa);
        free(_toRemove);
    }
}

static void Clear()
{
    IMAGE *_toRemove = NULL;
    IMAGE **tracer = &head;

    if(!(*tracer))
    {
        printf("\nQueue is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        while (*tracer)
        {
            printf("\nsuma de control -> %d\n", (*tracer) -> sumaDeControl);

            _toRemove = *tracer;
            *tracer = (*tracer) -> next;

            free(_toRemove -> secventa);
            free(_toRemove);
        }

        *tracer = NULL;
        tail = NULL;
    }
}

void ControlCoadaDinamicaLSI(int option)
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
            printf("\nSomething went Wrong with ControlCoadaDinamicaLSI!\n");
            break;
    }
}