#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct arbore
{
    int numar;
    struct arbore *left;
    struct arbore *right;
} TREE;

static TREE *head = NULL;

static TREE *NewElement(int numar)
{
    TREE *newp = (TREE*) malloc(sizeof(TREE));

    newp -> numar = numar;
    newp -> left = NULL;
    newp -> right = NULL;

    return newp;
}


static void Insert(TREE **tracer, TREE *newp)
{
    if (!(*tracer))     *tracer = newp;
    else
        if (newp -> numar < (*tracer) -> numar)
            Insert(&(*tracer) -> left, newp);
        else
            Insert(&(*tracer) -> right, newp);
}

static void InOrder(TREE **tracer)
{
    if (*tracer)
    {
        InOrder(&(*tracer) -> left);
        printf("%d ", (*tracer) -> numar);
        InOrder(&(*tracer) -> right);
    }
}

static TREE *FindSmallest(TREE **tracer)
{
    TREE *_smallest = *tracer;

    while (_smallest -> left)   _smallest = _smallest -> left;

    return _smallest;
}

static TREE *DeleteKey(TREE **tracer, int key)
{
    if (!(*tracer))     return (*tracer);

    if ((*tracer) -> numar > key)
        (*tracer) -> left = DeleteKey(&(*tracer) -> left, key); 
    else if ((*tracer) -> numar < key)
        (*tracer) -> right = DeleteKey(&(*tracer) -> right, key);
    else
    {
        if (!(*tracer) -> left)
        {
            TREE *_temp = (*tracer) -> right;
            
            free(*tracer);
            return _temp;
        }
        else if (!(*tracer) -> right)
        {
            TREE *_temp = (*tracer) -> left;

            free(*tracer);
            return _temp;
        }

        TREE *_temp = FindSmallest(&(*tracer) -> right);

        (*tracer) -> numar = _temp -> numar;

        (*tracer) -> right = DeleteKey(&(*tracer) -> right, key);
    }

    return (*tracer);
}


static void Update(TREE **tracer, int newNumber, int numberToDelete)
{
    DeleteKey(&head, numberToDelete);
    Insert(&head, NewElement(newNumber));

    printf("\nArborele a fost Actualizat cu Success!\n");
}

static void Delete(TREE **tracer)
{
    if (*tracer)
    {
        Delete(&(*tracer) -> left);
        Delete(&(*tracer) -> right);
        
        free(*tracer);
    }
}

static TREE *DeleteLeaves(TREE **tracer)
{
    if (!(*tracer) -> left && !(*tracer) -> right)
    {
        printf("%d ", (*tracer) -> numar);

        free(*tracer);
        return NULL;
    }

    (*tracer) -> left = DeleteLeaves(&(*tracer) -> left);
    (*tracer) -> right = DeleteLeaves(&(*tracer) -> right);

    return (*tracer);
}

static void DeleteLevel(TREE **tracer, int level)
{
    if (!(*tracer))     return;

    if (!level)     (*tracer) = DeleteKey(&(*tracer), (*tracer) -> numar);
    else
    {
        DeleteLevel(&(*tracer) -> left, level-1);
        DeleteLevel(&(*tracer) -> right, level-1);
    }
}

static int GenerateRandom()
{
    int numar;

    for(int i=0; i<100; ++i)
        numar = rand() % RAND_MAX;

    return numar;
}

static void Loading(float nr)
{
    (nr != 100.0)   ?   printf("Loading %.2f%%\r", nr)  :
                        printf("\rCompleted!       \n");
}

static void AutoGenerateTree(int size)
{
    fputs("\e[?25l", stdout);

    for(int i=0; i<size; ++i)
    {
        float y=i*100, x = size-1;
        Loading(y / x);
        Insert(&head, NewElement(GenerateRandom()));
    }

    fputs("\e[?25h", stdout);
    printf("\n\nArborele a fost generat cu Succes!\n");
}


void ControlOB(int option, int numar, int numarDelete)
{
    time_t t;
    srand((unsigned) time(&t));
    
    switch (option)
    {
        case 1:
            Insert(&head, NewElement(numar));
            break;
        case 2:
            InOrder(&head);
            break;
        case 3:
            DeleteKey(&head, numar);
            break;
        case 4:
            Update(&head, numar, numarDelete);
            break;
        case 5:
            Delete(&head);
            head = NULL;
            break;
        case 6:
            DeleteLeaves(&head);
            break;
        case 7:
            DeleteLevel(&head, numar);
            break;
        case 8:
            AutoGenerateTree(numar);
            break;
        default:
            printf("\nSomething went Wrong with ControlOB!\n");
            break;
    }
}