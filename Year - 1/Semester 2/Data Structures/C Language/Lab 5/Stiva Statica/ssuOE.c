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

static STACK1 ssuOE1[MAX];

static int top1 = -1;

static STACK2 ssuOE2[MAX];

static int top2 = -1;

static STACK3 ssuOE3[MAX];

static int top3 = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    MeniuPrincipal(2, 1);
}

static void Push1(unsigned cod,  unsigned cantitate)
{
    if (top1 == MAX-1)
    {
        printf("Stack Overflow!\n");

        ReturnToPrev();
    }
    else
    {
        ++top1;
        ssuOE1[top1].codProdus = cod;
        ssuOE1[top1].cantitate = cantitate;

        printf("Elementul a fost adaugat cu Succes!\n");
    }
}


static void Push2(unsigned cod,  float pret)
{
    if (top2 == MAX-1)
    {
        printf("Stack Overflow!\n");

        ReturnToPrev();
    }
    else
    {
        ++top2;
        ssuOE2[top2].codProdus = cod;
        ssuOE2[top2].pret = pret;

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
        printf("cod       -> %u\n", ssuOE1[top1].codProdus);
        printf("cantitate -> %u\n", ssuOE1[top1].cantitate);
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
        printf("cod  -> %u\n", ssuOE2[top2].codProdus);
        printf("pret -> %.2lf\n", ssuOE2[top2].pret);
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
        printf("cod       -> %u\n", ssuOE3[top3].codProdus);
        printf("cantitate -> %u\n", ssuOE3[top3].cantitate);
        printf("pret      -> %.2lf\n", ssuOE3[top3].pret);
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
            printf("cod       -> %u\n", ssuOE1[top1].codProdus);
            printf("cantitate -> %u\n", ssuOE1[top1].cantitate);
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
            printf("cod  -> %u\n", ssuOE2[top2].codProdus);
            printf("pret -> %.2lf\n", ssuOE2[top2].pret);
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
            if(ssuOE3[top3].pret == -1) 
            {
                printf("[-1]\n\n");
                continue;
            }

            printf("Elementul este:\n");
            printf("cod       -> %u\n", ssuOE3[top3].codProdus);
            printf("cantitate -> %u\n", ssuOE3[top3].cantitate);
            printf("pret      -> %.2lf\n", ssuOE3[top3].pret);
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
            if (ssuOE1[top1].codProdus == ssuOE2[top2].codProdus)
            {
                ++top3;
                ssuOE3[top3].codProdus = ssuOE1[top1].codProdus;
                ssuOE3[top3].cantitate = ssuOE1[top1].cantitate;
                ssuOE3[top3].pret = ssuOE2[top2--].pret * (double) ssuOE1[top1--].cantitate;

                continue;
            }

            if (ssuOE1[top1].codProdus > ssuOE2[top2].codProdus)
            {
                ++top3;
                ssuOE3[top3].pret = -1;

                --top1;

                continue;
            }

            if (ssuOE1[top1].codProdus < ssuOE2[top2].codProdus)
            {
                ++top3;
                ssuOE3[top3].pret = -1;

                --top2;

                continue;
            }
        }
    }

    printf("Stack3 a fost Generat cu Succes!\n");
}

void ControlSSUOE(int option, unsigned cod, unsigned cantitate, double pret)
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
            printf("\nSomething went Wrong with ControlSSUOE!\n");
            break;
    }
}