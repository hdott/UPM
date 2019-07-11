#include <stdio.h>
#include <stdlib.h>
#include "meniu.h"
#define MAX 10


static unsigned alloc = 0;

static unsigned maximum = 0;

static unsigned *sse = NULL;

static int top = -1;


static int ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    MeniuPrincipal(1, 2);
}

static void Push(unsigned element)
{
    if (top == maximum-1)
    {
        unsigned *_aux = NULL;
        ++alloc;

        _aux = realloc(sse, (maximum = alloc * MAX) * sizeof(unsigned));

        if (!_aux)
        {
            printf("Something went Wrong Resizing the Stack!\n");

            ReturnToPrev();
        }
        else
        {
            ++top;
            sse = _aux;
            *(sse+top) = element;
            _aux = NULL;

            printf("Elementul a fost adaugat cu Succes!\n");
        }
    }
    else
    {
        ++top;
        *(sse+top) = element;

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
        printf("Elementul este -> %u\n", *(sse+top));
        --top;
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
            printf("ELementul este -> %u\n", *(sse+top));

        free(sse);
    }
}

void ControlSSE(int option, unsigned element)
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
            printf("\nSomething went Wrong with ControlSSE!\n");
            break;
    }
}