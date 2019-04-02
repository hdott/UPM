#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b)  (((a) > (b)) ? (a) : (b))

typedef struct arbore
{
    int numar;
    struct arbore *left;
    struct arbore *right;
    int height;
} TREE;

static TREE *head = NULL;

static TREE *NewElement(int numar)
{
    TREE *newp = (TREE*) malloc(sizeof(TREE));

    newp -> numar = numar;
    newp -> left = NULL;
    newp -> right = NULL;
    newp -> height = 1;

    return newp;
}

static int Height(TREE **tracer)
{
    if(!(*tracer))  return 0;

    return (*tracer) -> height;
}

static TREE *RightRotate(TREE **tracer)
{
    TREE *_aux = (*tracer) -> left;
    TREE *_T2 = _aux -> right;

    _aux -> right = *tracer;
    (*tracer) -> left = _T2;

    (*tracer) -> height = max(Height(&(*tracer) -> left), 
                                    Height(&(*tracer) -> right) + 1);
    _aux -> height = max(Height(&_aux -> left), Height(&_aux -> right) + 1);

    return _aux;
}

static TREE *LeftRotate(TREE **tracer)
{
    TREE *_aux = (*tracer) -> right;
    TREE *_T2 = _aux -> left;

    _aux -> left = *tracer;
    (*tracer) -> right = _T2;

    (*tracer) -> height = max(Height(&(*tracer) -> left),
                                Height(&(*tracer) -> right) + 1);
    _aux -> height = max(Height(&_aux -> left), Height(&_aux -> right) + 1);

    return _aux;
}

static int GetBalance(TREE **tracer)
{
    if(!(*tracer))  return 0;

    return Height(&(*tracer) -> left) - Height(&(*tracer) -> right);
}

static TREE *Insert(TREE **tracer, int numar)
{
    if(!(*tracer))  return NewElement(numar);

    if(numar < (*tracer) -> numar)
        (*tracer) -> left = Insert(&(*tracer) -> left, numar);
    else if(numar > (*tracer) -> numar)
        (*tracer) -> right = Insert(&(*tracer) -> right, numar);
    else    return *tracer;

    (*tracer) -> height = 1 + max(Height(&(*tracer) -> left),
                                        Height(&(*tracer) -> right));

    int balance = GetBalance(tracer);

    if(balance > 1 && numar < (*tracer) -> left -> numar)
        return RightRotate(tracer);

    if(balance < -1 && numar > (*tracer) -> right -> numar)
        return LeftRotate(tracer);

    if(balance > 1 && numar > (*tracer) -> left -> numar)
    {
        (*tracer) -> left = LeftRotate(&(*tracer) -> left);

        return RightRotate(tracer);
    }                              

    if(balance < -1 && numar < (*tracer) -> right -> numar)
    {
        (*tracer) -> right = RightRotate(&(*tracer) -> right);

        return LeftRotate(tracer);
    }

    return *tracer;
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

static void AutoGenerateTree()
{
    int size;
    printf("\nInsert the size of the tree:\n");
    printf("(int): ");
    scanf("%d", &size);
    getchar();
    puts("");
    fputs("\e[?25l", stdout);

    for(int i=0; i<size; ++i)
    {
        float y=i*100, x=size-1;
        Loading(y / x);

        head = Insert(&head, GenerateRandom());
    }

    fputs("\e[?25h", stdout);
    printf("\n\nArborele a fost generat cu Succes!\n");
}


static void InOrder(TREE **tracer)
{
    if(*tracer)
    {
        InOrder(&(*tracer) -> left);
        printf("%d ", (*tracer) -> numar);
        InOrder(&(*tracer) -> right);
    }
}

static void PreOrder(TREE **tracer)
{
    if(*tracer)
    {
        printf("%d ", (*tracer) -> numar);
        PreOrder(&(*tracer) -> left);
        PreOrder(&(*tracer) -> right);
    }
}

static void PostOrder(TREE **tracer)
{
    if(*tracer)
    {
        PostOrder(&(*tracer) -> left);
        PostOrder(&(*tracer) -> right);
        printf("%d ", (*tracer) -> numar);
    }
}

static void Delete(TREE **tracer)
{
    if(*tracer)
    {
        Delete(&(*tracer) -> left);
        Delete(&(*tracer) -> right);

        free(*tracer);
    }
}


void ControlFunctions(int option)
{
    time_t t;
    srand((unsigned) time(&t));

    switch (option)
    {
        case 1:
            AutoGenerateTree();
            break;
        case 2:
            InOrder(&head);
            break;
        case 3:
            PreOrder(&head);
            break;
        case 4:
            PostOrder(&head);
            break;
        case 5:
            if(head)
            {
                Delete(&head);
                head = NULL;
            }
            break;
        default:
            printf("\nSomething went Wrong with ControlFunctions!\n");
            break;
    }
}