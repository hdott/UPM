#include <stdio.h>
#include <stdlib.h>
#include "meniu.h"
#define MAX 10

typedef struct Stiva1
{
    unsigned codProdus;
    unsigned cantitate;
} STACK1;

typedef struct Stiva2
{
    unsigned codProdus;
    double pret;
} STACK2;

typedef struct Stiva3
{
    unsigned codProdus;
    unsigned cantitate;
    double pret;
} STACK3;

static STACK1 *sseOE1 = NULL;

static unsigned alloc1 = 0;

static unsigned maximum1 = 0;

static int top1 = -1;

static STACK2 *sseOE2 = NULL;

static unsigned alloc2 = 0;

static unsigned maximum2 = 0;

static int top2 = -1;

static STACK3 *sseOE3 = NULL;

static unsigned alloc3 = 0;

static unsigned maximum3 = 0;

static int top3 = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    MeniuPrincipal(2, 2);
}

static void Push1(unsigned cod, unsigned cantitate)
{
    if (top1 == maximum1-1)
    {
        STACK1 *_aux = NULL;
        ++alloc1;

        _aux = (STACK1*) realloc(sseOE1, (maximum1 = alloc1 * MAX) * sizeof(STACK1));

        if (!_aux)
        {
            printf("Something went Wrong Resizing the Stack1!\n");

            ReturnToPrev();
        }
        else
        {
            ++top1;
            sseOE1 = _aux;
            sseOE1[top1].codProdus = cod;
            sseOE1[top1].cantitate = cantitate;
            _aux = NULL;

            printf("Elementul a fost adaugat cu Succes!\n");
        }
    }
    else
    {
        ++top1;
        sseOE1[top1].codProdus = cod;
        sseOE1[top1].cantitate = cantitate;

        printf("Elementul a fost adaugat cu Succes!\n");
    }
}

static void Push2(unsigned cod, double pret)
{
    if (top2 == maximum2-1)
    {
        STACK2 *_aux = NULL;
        ++alloc2;

        _aux = (STACK2*) realloc(sseOE2, (maximum2 = alloc2 * MAX) * sizeof(STACK2));

        if (!_aux)
        {
            printf("Something went Wrong Resizing the Stack2!\n");

            ReturnToPrev();
        }
        else
        {
            ++top2;
            sseOE2 = _aux;
            sseOE2[top2].codProdus = cod;
            sseOE2[top2].pret = pret;
            _aux = NULL;

            printf("Elementul a fost adaugat cu Succes!\n");
        }
    }
    else
    {
        ++top2;
        sseOE2[top2].codProdus = cod;
        sseOE2[top2].pret = pret;

        printf("Elementul a fost adaugat cu Succes!\n");
    }
}

static void Pop1()
{
    if (top1 == -1)
    {
        printf("Stack Underflow!\n");

        ReturnToPrev();
    }
    else
    {
        printf("Elementul este:\n");
        printf("cod       -> %u\n", sseOE1[top1].codProdus);
        printf("cantitate -> %u\n", sseOE1[top1].cantitate);
        --top1;
    }
}

static void Pop2()
{
    if (top2 == -1)
    {
        printf("Stack Underflow!\n");

        ReturnToPrev();
    }
    else
    {
        printf("Elementul este:\n");
        printf("cod  -> %u\n", sseOE2[top2].codProdus);
        printf("pret -> %.2lf\n", sseOE2[top2].pret);
        --top2;
    }
}

static void Pop3()
{
    if (top3 == -1)
    {
        printf("Stack Underflow!\n");

        ReturnToPrev();
    }
    else
    {
        printf("Elementul este:\n");
        printf("cod       -> %u\n", sseOE3[top3].codProdus);
        printf("cantitate -> %u\n", sseOE3[top3].cantitate);
        printf("pret      -> %.2lf\n", sseOE3[top3].pret);
        --top3;
    }
}

static void Clear1()
{
    if (top1 == -1)
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {   
        for( ; top1>=0; --top1)
        {
            printf("Elementul este:\n");
            printf("cod       -> %u\n", sseOE1[top1].codProdus);
            printf("cantitate -> %u\n", sseOE1[top1].cantitate);
            puts("");
        }
    }
}

static void Clear2()
{
    if (top2 == -1)
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {   
        for( ; top2>=0; --top2)
        {
            printf("Elementul este:\n");
            printf("cod  -> %u\n", sseOE2[top2].codProdus);
            printf("pret -> %.2lf\n", sseOE2[top2].pret);
            puts("");
        }
    }
}

static void Clear3()
{
    if (top3 == -1)
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {   
        for( ; top3>=0; --top3)
        {
            if(sseOE3[top3].pret == -1) 
            {
                printf("[-1]\n\n");
                continue;
            }

            printf("Elementul este:\n");
            printf("cod       -> %u\n", sseOE3[top3].codProdus);
            printf("cantitate -> %u\n", sseOE3[top3].cantitate);
            printf("pret      -> %.2lf\n", sseOE3[top3].pret);
            puts("");
        }
    }
}

static void GenerateStack3()
{
    if (top1 == -1)
    {
        printf("Stack1 is Empty!\n");

        ReturnToPrev();
    }
    else if (top2 == -1)
    {
        printf("Stack2 is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        for( ; top1>=0 && top2>=0; )
        {
            if (top3 == maximum3-1)
            {
                STACK3 *_aux = NULL;
                ++alloc3;

                _aux = (STACK3*) realloc(sseOE3, (maximum3 = alloc3 * MAX) * sizeof(STACK3));

                if (!_aux)
                {
                    printf("Something went Wrong Resizing the Stack3!\n");

                    ReturnToPrev();
                }
                else
                {
                    sseOE3 = _aux;
                    _aux = NULL;
                }
            }

            if (sseOE1[top1].codProdus == sseOE2[top2].codProdus)
            {
                ++top3;
                sseOE3[top3].codProdus = sseOE1[top1].codProdus;
                sseOE3[top3].cantitate = sseOE1[top1].cantitate;
                sseOE3[top3].pret = sseOE2[top2--].pret * (double) sseOE1[top1--].cantitate;

                continue;
            }

            if (sseOE1[top1].codProdus > sseOE2[top2].codProdus)
            {
                ++top3;
                sseOE3[top3].pret = -1;

                --top1;

                continue;
            }

            if (sseOE1[top1].codProdus < sseOE2[top2].codProdus)
            {
                ++top3;
                sseOE3[top3].pret = -1;

                --top2;

                continue;
            }
        }
    }

    printf("Stack3 a fost Generat cu Succes!\n");
}

void ControlSSEOE(int option, unsigned cod, unsigned cantitate, double pret)
{
    switch (option)
    {
        case 1:
            Push1(cod, cantitate);
            break;
        case 2:
            Push2(cod, pret);
            break;
        case 3:
            Pop1();
            break;
        case 4:
            Pop2();
            break;
        case 5:
            Clear1();
            break;
        case 6:
            Clear2();
            break;
        case 7:
            GenerateStack3();
            break;
        case 8:
            Pop3();
            break;
        case 9:
            Clear3();
            break;
        default:
            printf("\nSomething went Wrong with ControlSSEOE!\n");
            break;
    }
}