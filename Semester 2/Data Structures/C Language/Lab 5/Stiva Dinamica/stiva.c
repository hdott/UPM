#include <stdio.h>
#include <stdlib.h>
#include "meniu.h"


typedef struct stiva
{
    char paranteza;
    struct stiva *next;
} STACK;

STACK *head = NULL;

STACK *NewStack(char paranteza)
{
    STACK *newp = (STACK*) malloc(sizeof(STACK));

    newp -> paranteza = paranteza;
    newp -> next = NULL;

    return newp;
}


static void ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();

    Meniu(0);
}

static void Push(STACK *newp)
{
    STACK **tracer = &head;

    if(!(*tracer))  *tracer = newp;
    else
    {
        newp -> next = *tracer;
        *tracer = newp;
    }
}

static void Pop()
{
    STACK *_toRemove = NULL;
    STACK **tracer = &head;

    if(!(*tracer))
    {
        printf("Stack Underflow!\n");
        
        ReturnToPrev();
    }
    else if(*tracer)
    {
        printf("caracterul ->  %c\n", (*tracer) -> paranteza);
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free (_toRemove);
    }
}

static void Peek()
{
    STACK **tracer = &head;

    if(!(*tracer))
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else    printf("caracterul ->  %c\n", (*tracer) -> paranteza);
}

static void IsEmpty()
{
    STACK **tracer = &head;

    if(!(*tracer))
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        printf("Stack is Not Empty!\n");

        ReturnToPrev();
    }

}

static void Clear()
{
    STACK *_toRemove = NULL;
    STACK **tracer = &head;

    if(!(*tracer))
    {
        printf("Stack is Empty!\n");

        ReturnToPrev();
    }
    else
    {
        while(*tracer)
        {
            printf("caracterul ->  %c\n", (*tracer) -> paranteza);

            _toRemove = *tracer;
            *tracer = (*tracer) -> next;

            free (_toRemove);
        }
    }
}


STACK *headCE = NULL;

static void PushCE(STACK *newp)
{
    STACK **tracer = &headCE;

    if(!(*tracer))  *tracer = newp;
    else
    {
        newp -> next = *tracer;
        *tracer = newp;
    }
}

static char PopCE()
{
    char paranteza;
    STACK *_toRemove = NULL;
    STACK **tracer = &headCE;

    if(!(*tracer))  
    {
        printf("\nStack is Empty!\n");

        ReturnToPrev();
    }
    else if(*tracer)
    {
        _toRemove = *tracer;
        paranteza = _toRemove -> paranteza;
        *tracer = (*tracer) -> next;

        free (_toRemove);
    }

    return paranteza;
}

void static CheckExpression()
{
    printf("\nIntroduceti un sir de paranteze si simboluri:\n");
    char ch, ch1;

    do
    {
        ch = getchar();

        if(ch == '\n' && ch == ' ')     break;

        if(ch == '(' || ch == '[' || ch == '{')
        {
            PushCE(NewStack(ch));

            continue;
        }

        switch (ch)
        {
            case ')':
                if((ch1 = PopCE()) != '(')
                {
                    do
                    {
                        printf("\nPereche Inexistenta pentru '%c'!\n", ch1);   
                    } while ((ch1 = PopCE()) != '(');
                }

                if(ch1 == '(')
                {
                    printf("\nPereche existenta pentru '('!\n");
                    printf("caracterul -> %c\n", ch);
                }
                
                break;
            case ']':
                if((ch1 = PopCE()) != '[')
                {
                    do
                    {
                        printf("\nPereche Inexistenta pentru '%c'!\n", ch1);   
                    } while ((ch1 = PopCE()) != '[');
                }

                if(ch1 == '[')
                {
                    printf("\nPereche existenta pentru '['!\n");
                    printf("caracterul -> %c\n", ch);
                }
                
                break;
            case '}':
                if((ch1 = PopCE()) != '{')
                {
                    do
                    {
                        printf("\nPereche Inexistenta pentru '%c'!\n", ch1);   
                    } while ((ch1 = PopCE()) != '{');
                }

                if(ch1 == '{')
                {
                    printf("\nPereche existenta pentru '{'!\n");
                    printf("caracterul -> %c\n", ch);
                }
                
                break;
        }
    } while (ch != '\n' && ch != ' ');

    PopCE();
}

void ControlStack(int option, STACK *newp)
{
    switch (option)
    {
        case 1:
            Push(newp);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            IsEmpty();
            break;
        case 5:
            Clear();
            break;
        case 6:
            CheckExpression();
            break;
        default:
            printf("\nSomething went Wrong with ControlStack!\n");
            break;
    }
}