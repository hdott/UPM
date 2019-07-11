#include <stdio.h>
#include <stdlib.h>
#include "meniu.h"


typedef struct lista
{
    struct lista *previous;
    unsigned number;
    struct lista *next;
} LIST;

LIST *head = NULL;
LIST *tail = NULL;


LIST *NewElement(unsigned number)
{
    LIST *newp = (LIST*) malloc(sizeof(LIST));

    newp -> number = number;
    newp -> previous = NULL;
    newp -> next = NULL;

    return newp;
}


// Insert Functions
static void InsertElementStart(LIST *newp)
{
    LIST **tracer = &head;

    if(!(*tracer))
    {
        *tracer = newp;
        tail = newp;
    }
    else
    {
        newp -> next = *tracer;
        (*tracer) -> previous = newp;
        *tracer = newp;
    }
}

static void InsertElementEnd(LIST *newp)
{
    LIST **tracer =  &tail;

    if(!(*tracer))
    {
        *tracer = newp;
        head =  newp;
    }
    else
    {
        (*tracer) -> next = newp;
        newp -> previous = *tracer;
        *tracer = newp;
    }
}

static void EmptyListInsert(LIST *newp)
{
    char ch;

    printf("Lista este goala! Doriti sa introduceti elementul?\n");
        printf("(y/N): ");
        scanf("%c", &ch);
        getchar();

    (ch == 'y') ?   InsertElementEnd(newp)  :
                    MeniuPrincipal(1);
}

static void MissingElementInsert()
{
    char ch;

    getchar();
    printf("\nElementul nu a fost gasit in lista actuala!\n");
    printf("\nReintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(1) :
                    exit(1); 
}

static void InsertBefore(unsigned key, LIST *newp)
{
    LIST **tracer = &head;
    _Bool present = 0;
    
    if(!(*tracer))                          EmptyListInsert(newp);
    else if((*tracer) -> number == key)     InsertElementStart(newp);
    else
    {
        while((*tracer) -> next && (*tracer) -> next -> number != key)
            tracer = &(*tracer) -> next;

        if((*tracer) -> next && (*tracer) -> next -> number == key)
        {
            newp -> next = (*tracer) -> next;
            newp -> previous = *tracer;
            (*tracer) -> next -> previous = newp;
            (*tracer) -> next = newp;

            present = 1;
        }

        if(!present)    MissingElementInsert();
    }
}

static void InsertAfter(unsigned key, LIST *newp)
{
    LIST **tracer = &head;
    _Bool present = 0;

    if(!(*tracer))                          EmptyListInsert(newp);
    else if((*tracer) -> number == key)     InsertElementStart(newp);
    else if(tail && tail -> number == key)  InsertElementEnd(newp);
    else
    {
        while(*tracer && (*tracer) -> number != key)
            tracer = &(*tracer) -> next;

        if(*tracer && (*tracer) -> number == key)
        {
            if(!(*tracer) -> next)  tail = newp;
            
            newp -> next = (*tracer) -> next;
            newp -> previous = *tracer;
            (*tracer) -> next -> previous = newp;
            (*tracer) -> next = newp;

            present = 1;
        }

        if(!present)    MissingElementInsert();
    }
}


// Delete Functions
static void EmptyListDelete()
{
    char ch;

    printf("Lista este goala! Reintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);
        getchar();

    (ch == 'y') ?   MeniuPrincipal(2) :
                    exit(1);
}

static void MissingElementDelete()
{
    char ch;

    getchar();
    printf("\nElementul nu a fost gasit in lista actuala!\n");
    printf("\nReintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(2) :
                    exit(1); 
}

static void DeleteFirst()
{
    LIST *_toDelete = NULL;
    LIST **tracer = &head;
    
    if(!(*tracer))      EmptyListDelete();
    else
    {
        _toDelete = *tracer;
        *tracer = (*tracer) -> next;
        (*tracer) -> previous = NULL;

        free(_toDelete);
    }
}

static void DeleteLast()
{
    LIST *_toDelete = NULL;
    LIST **tracer = &tail;

    if(!(*tracer))      EmptyListDelete();
    else
    {
        _toDelete = *tracer;
        *tracer = (*tracer) -> previous;
        (*tracer)  -> next = NULL;

        free(_toDelete);
    }
}

static void DeleteKey(unsigned key)
{
    LIST *_toDelete = NULL;
    LIST **tracer = &head;
    _Bool present = 0;

    if(!(*tracer))      EmptyListDelete();
    else if(*tracer && (*tracer) -> number == key)  DeleteFirst();
    else if(tail && tail -> number == key)          DeleteLast();
    else
    {
        while(*tracer && (*tracer) -> number != key)
            tracer = &(*tracer) -> next;
        
        if(*tracer && (*tracer) -> number == key)
        {
            _toDelete = *tracer;
            tracer = &(*tracer) -> previous;
            (*tracer) -> next = (*tracer) -> next -> next;
            (*tracer) -> next -> previous = *tracer;

            free(_toDelete);

            present = 1;
        }

        if(!present)    MissingElementDelete();
    }
}


// Search Functions
static void EmptyListSearch()
{
    char ch;

    getchar();
    printf("Lista este goala! Reintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(0) :
                    exit(1);
}

static void MissingElementSearch()
{
    char ch;

    getchar();
    printf("\nElementul nu a fost gasit in lista actuala!\n");
    printf("\nReintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(0) :
                    exit(1); 
}

static void PrintElement(LIST **tracer)
{
    getchar();
    printf("\nElementul a fost gasit in lista actuala!\n");
    printf("%u\n", (*tracer) -> number);
}

static void SearchKey(unsigned key)
{
    LIST **tracer = &head;
    _Bool present = 0;

    if(!(*tracer))                                      EmptyListSearch();
    else if(*tracer && (*tracer) -> number == key)      PrintElement(tracer);
    else if(tail && tail -> number == key)              PrintElement(&tail);
    else
    {
        while(*tracer && (*tracer) -> number != key)
            tracer = &(*tracer) -> next;

        if(*tracer && (*tracer) -> number == key)
        {
            PrintElement(tracer);

            present = 1;
        }

        if(!present)    MissingElementSearch();
    }
}


// Print Functions
static void EmptyListPrint()
{
    char ch;

    printf("Lista este goala! Reintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(4) :
                    exit(1);
}

static void PrintListFirstLast()
{
    LIST **tracer = &head;

    if(!(*tracer))      EmptyListPrint();
    else
    {
        while(*tracer)
        {
            printf("%u\n", (*tracer) -> number);

            tracer = &(*tracer) -> next;
        }
    }
}

static void PrintListLastFirst()
{
    LIST **tracer = &tail;

    if(!(*tracer))      EmptyListPrint();
    else
    {
        while(*tracer)
        {
            printf("%u\n", (*tracer) -> number);

            tracer = &(*tracer) -> previous;
        }
    }
}


// Destroy Functions
static void EmptyListDestroy()
{
    char ch;

    getchar();
    printf("Lista este goala! Reintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(0) :
                    exit(1);
}

static void DestroyWholeList()
{
    LIST *_toDelete = NULL;
    LIST **tracer = &head;

    if(!(*tracer))      EmptyListDestroy();
    else
    {
        while(*tracer)
        {
            _toDelete = *tracer;
            tracer = &(*tracer) -> next;

            free(_toDelete);
        }

        head = NULL;
        tail = NULL;
    }
}


// Operatii Extinse Functions
static void EmptyListOpExtinse()
{
    char ch;

    getchar();
    printf("Lista este goala! Reintoarcere la meniul anterior?\n");
        printf("(y/N): ");
        scanf("%c", &ch);

    (ch == 'y') ?   MeniuPrincipal(6) :
                    exit(1);
}

LIST *headTemp = NULL;
LIST *tailTemp = NULL;

static void InsertTempEnd(LIST *newp)
{
    LIST **tracer =  &tailTemp;

    if(!(*tracer))
    {
        *tracer = newp;
        headTemp =  newp;
    }
    else
    {
        (*tracer) -> next = newp;
        newp -> previous = *tracer;
        *tracer = newp;
    }
}

static void DestroyWholeTemp()
{
    LIST *_toDelete = NULL;
    LIST **tracer = &headTemp;

    if(!(*tracer))      EmptyListDestroy();
    else
    {
        while(*tracer)
        {
            _toDelete = *tracer;
            tracer = &(*tracer) -> next;

            free(_toDelete);
        }

        headTemp = NULL;
        tailTemp = NULL;
    }
}

static void RemoveDuplicates()
{
    LIST **tracer = &head;

    if(!(*tracer))      EmptyListOpExtinse();
    else
    {
        while(*tracer)
        {
            LIST **tracerTemp = &headTemp;
            _Bool present = 0;

            while(*tracerTemp)
            {
                if((*tracer) -> number == (*tracerTemp) -> number)
                {
                    present = 1;
                    break;
                }

                tracerTemp = &(*tracerTemp) -> next;
            }

            if(!present)    InsertTempEnd(NewElement((*tracer) -> number));

            tracer = &(*tracer) -> next;
        }
    }

    LIST *pAuxHead = headTemp;
    LIST *pAuxTail = tailTemp;
    headTemp = head;
    tailTemp = tail;
    head = pAuxHead;
    tail = pAuxTail;

    DestroyWholeTemp();
}

static void AddAfterDivisor(unsigned key)
{
    LIST **tracer = &head;

    if(!(*tracer))      EmptyListOpExtinse();
    else
    {
        while(*tracer)
        {
            if(*tracer && !(key % (*tracer) -> number))
            {
                LIST *newp = NewElement(key);

                if(!(*tracer) -> next)  tail = newp;

                newp -> next = (*tracer) -> next;
                newp -> previous = *tracer;
                (*tracer) -> next -> previous = newp;
                (*tracer) -> next = newp;

                if(!(*tracer) -> next -> next)  break;
                else
                {
                    tracer = &(*tracer) -> next -> next;
                    continue;
                }
            }
            
            tracer = &(*tracer) -> next;
        }
    }
}

static void OrderAscending()
{
    LIST **tracer1 = &head;
    LIST **tracer2 = NULL;

    if(!(*tracer1))      EmptyListOpExtinse();
    else
    {
        while((*tracer1) -> next)
        {
            tracer2 = &(*tracer1) -> next;
            while(*tracer2)
            {
                if((*tracer1) -> number > (*tracer2) -> number)
                {
                    unsigned Aux = (*tracer1) -> number;
                    (*tracer1) -> number = (*tracer2) -> number;
                    (*tracer2) -> number = Aux;
                }

                tracer2 = &(*tracer2) -> next;
            }

            tracer1 =&(*tracer1) -> next;
        }
    }

}

static void OrderDescending()
{
    LIST **tracer1 = &head;
    LIST **tracer2 = NULL;
    LIST *pAux;

    if(!(*tracer1))      EmptyListOpExtinse();
    else
    {
        while((*tracer1) -> next)
        {
            tracer2 = &(*tracer1) -> next;

            while(*tracer2)
            {
                if((*tracer1) -> number < (*tracer2) -> number)
                {
                    unsigned Aux = (*tracer1) -> number;
                    (*tracer1) -> number = (*tracer2) -> number;
                    (*tracer2) -> number = Aux;
                }

                tracer2 = &(*tracer2) -> next;
            }

            tracer1 = &(*tracer1) -> next;
        }
    }

}

static void AddLink(int option, unsigned key, LIST *newp)
{
    switch (option)
    {
        case 1:
            InsertElementStart(newp);
            break;
        case 2:
            InsertElementEnd(newp);
            break;
        case 3:
            InsertBefore(key, newp);
            break;
        case 4:
            InsertAfter(key, newp);
            break;
        default:
            printf("Something went Wrong with AddLink!\n");
            break;
    }
}

static void DeleteLink(int option, unsigned key)
{
    switch (option)
    {
        case 1:
            DeleteFirst();
            break;
        case 2:
            DeleteLast();
            break;
        case 3:
            DeleteKey(key);
            break;
        default:
            printf("Something went Wrong with DeleteLink!\n");
            break;
    }
}

static void PrintLink(int option)
{
    switch (option)
    {
        case 1:
            PrintListFirstLast();
            break;
        case 2:
            PrintListLastFirst();
            break;
        default:
            printf("Something went Wrong with PrintLink!\n");
            break;
    }
}

static void OpExtinseLink(int option, unsigned key)
{
    switch (option)
    {
        case 1:
            RemoveDuplicates();
            break;
        case 2:
            AddAfterDivisor(key);
            break;
        case 3:
            OrderAscending();
            break;
        case 4:
            OrderDescending();
            break;
        default:
            printf("Something went Wrong with OpExtinseLink!\n");
            break;
    }
}

void ControlLink(int option1, int option2, unsigned key, LIST *newp)
{
    switch (option1)
    {
        case 1:
            AddLink(option2, key, newp);
            break;
        case 2:
            DeleteLink(option2, key);
            break;
        case 3:
            SearchKey(key);
            break;
        case 4:
            PrintLink(option2);
            break;
        case 5:
            DestroyWholeList();
            break;
        case 6:
            OpExtinseLink(option2, key);
            break;
        default:
            printf("Something went Wrong with ControlLink!\n");
            break;
    }
}