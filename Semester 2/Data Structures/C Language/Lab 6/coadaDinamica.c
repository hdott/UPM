#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meniu.h"
#define MAX 5
#define MAXS 14
#define MAXL 30


typedef struct coada
{
    char nume[MAXL];
    char prenume[MAXL];
    unsigned serie[MAXS];
} QUEUE;

static unsigned alloc = 0;

static unsigned maximum = 0;

static QUEUE *vector = NULL;

static unsigned head = 0;
static int tail = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    ControlMeniu(1, 2);
}

static void Enqueue(char nume[], char prenume[], unsigned serie[])
{
    if (tail == maximum-1)
    {
        QUEUE *_aux = NULL;
        ++alloc;

        _aux = realloc(vector, (maximum = alloc * MAX) * sizeof(QUEUE));

        if(!_aux)
        {
            printf("\nSomething went Wrong Resizing the Queue!\n");

            ReturnToPrev();
        }
        else
        {
            ++tail;
            vector = _aux;

            strcpy(vector[tail].nume, nume);
            strcpy(vector[tail].prenume, prenume);
            for(int i=0; i<MAXS; ++i)
                vector[tail].serie[i] = serie[i];

            printf("\nElementul a fost adaugat cu Succes!\n");    
        }
    }
    else
    {
        ++tail;

        strcpy(vector[tail].nume, nume);
        strcpy(vector[tail].prenume, prenume);
        for(int i=0; i<MAXS; ++i)
            vector[tail].serie[i] = serie[i];

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
        printf("\nElementul este:\n");
        printf("nume    -> %s\n", vector[head].nume);
        printf("prenume -> %s\n", vector[head].prenume);
        printf("serie   -> ");
            for(int i=0; i<MAXS; ++i)
                printf("%u", vector[head].serie[i]);
            puts("");

        for(int i=0; i<tail; ++i)
            vector[i] = vector[i+1];

        tail--;
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
        for(; tail>=0; --tail)
        {
            printf("\nElementul este:\n");
            printf("nume    -> %s\n", vector[head].nume);
            printf("prenume -> %s\n", vector[head].prenume);
            printf("serie   -> ");
                for(int i=0; i<MAXS; ++i)
                    printf("%u", vector[head].serie[i]);
                printf("\n\n");

            for(int i=0; i<tail; ++i)
                vector[i] = vector[i+1];
        }

        free(vector);
    }
}

void ControlCoadaDinamica(int option, char nume[], char prenume[], unsigned serie[])
{
    switch (option)
    {
        case 1:
            Enqueue(nume, prenume, serie);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Clear();
            break;
        default:
            printf("\nSomething went Wrong with ControlCoadaDinamica!\n");
            break;
    }
}