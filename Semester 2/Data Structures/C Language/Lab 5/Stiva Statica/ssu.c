#include <stdio.h>
#include <stdlib.h>
#include "meniu.h"
#define MAX 10

static unsigned ssu[MAX];

static int top = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    MeniuPrincipal(1, 1);
}

static void Push(unsigned element)
{
    if (top == MAX-1)
    {
        printf("Stack Overflow!\n");

        ReturnToPrev();
    }
    else
    {
        ssu[++top] = element;

        printf("Elementul a fost adaugat cu Succes!\n");
    }
}

static void Pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");

        ReturnToPrev();
    }
    else
    {
        printf("Elementul este -> %u\n", ssu[top--]);
    }
}

static void Clear()
{
    if (top == -1)
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        for( ; top>=0; --top)
            printf("Elementul este -> %u\n", ssu[top]);
    }
}

void ControlSSU(int option, unsigned element)
{
    switch (option)
    {
        case 1:
            Push(element);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Clear();
            break;
        default:
            printf("\nSomething went Wrong with ControlSSU!\n");
            break;
    }
}
