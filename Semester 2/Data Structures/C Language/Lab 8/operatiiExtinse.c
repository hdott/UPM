#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MAX 100

typedef struct copac
{
    int numar;
    struct copac *left;
    struct copac *right;
} TREE;

static TREE *head = NULL;
int size;

static int GenerateRandom()
{
    int numar;

    for(int i=0; i<100; ++i)
        numar = rand() % RAND_MAX;

    return numar;
}

static TREE *NewElement()
{
    TREE *newp = (TREE*) malloc(sizeof(TREE));

    newp -> numar = GenerateRandom();
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

static void Loading(float nr)
{
    (nr != 100.0)   ?   printf("Loading %.2f%%\r", nr)  :
                        printf("\rCompleted!       \n");
}

static void CreateTree()
{
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
        Insert(&head, NewElement());
    }

    fputs("\e[?25h", stdout);
    printf("\n\nCopacul a fost generat cu Succes!\n");
}

// inorder+postorder = preorder
// inorder+preorder = postorder
static int *InOrder = NULL;
static int *PreOrder = NULL;
static int *PostOrder = NULL;

static int sizeIn = -1;
static int sizePre = -1;
static int sizePost = -1;

static int headPreTemp = 0;
static int sizePostTemp;

static int allocIn = 0;
static int allocPre = 0;
static int allocPost = 0;

static int maximumIn = 0;
static int maximumPre = 0;
static int maximumPost = 0;


static void Enqueue(int numar, int **order, int *size, int *alloc, int *maximum)
{
    if (*size == *maximum -1)
    {
        int *_aux = NULL;
        ++(*alloc);

        _aux = (int*) realloc(*order, (*maximum = *alloc * MAX) * sizeof(int));

        if(!_aux)
        {
            printf("\nSomething went Wrong Resizing!\n");

            exit(1);
        }
        else
        {
            ++(*size);
            *order = _aux;

            *(*order+*size) = numar;
        }
    }
    else
    {
        ++(*size);

        *(*order+*size) = numar;
    }
}

static void InOrderTemp(TREE **tracer)
{
    if(*tracer)
    {
        InOrderTemp(&(*tracer) -> left);
        Enqueue((*tracer) -> numar, &InOrder, &sizeIn, &allocIn, &maximumIn);
        InOrderTemp(&(*tracer) -> right);
    }
}

static void PostOrderTemp(TREE **tracer)
{
    if(*tracer)
    {
        PostOrderTemp(&(*tracer) -> left);
        PostOrderTemp(&(*tracer) -> right);
        Enqueue((*tracer) -> numar, &PostOrder, &sizePost, &allocPost, &maximumPost);
    }
}

static int SearchIn(int value)
{
    for(int i=0; i<=sizeIn; ++i)
        if (InOrder[i] == value)
            return i;

    return -1;
}

static void PreOrderTemp(int start, int end)
{
    if (start > end)    return;

    int numar = PostOrder[sizePostTemp--];
    int indexIn = SearchIn(numar);

    PreOrderTemp(indexIn+1, end);
    PreOrderTemp(start, indexIn-1);

    Enqueue(numar, &PreOrder, &sizePre, &allocPre, &maximumPre);
}

static void InOrderPostOrder()
{
    InOrderTemp(&head);
    PostOrderTemp(&head);

    sizePostTemp = sizePost;
    PreOrderTemp(0, sizeIn);
    
    printf("\nInOrder:\n");
    for(int i=0; i<=sizeIn; ++i)
        printf("%d ", InOrder[i]);
    puts("");

    printf("\nPostOrder:\n");
    for(int i=0; i<=sizePost; ++i)
        printf("%d ", PostOrder[i]);
    puts("");

    printf("\nPreOrder from InOrder & PostOrder:\n");
    for(int i=sizePre; i>=0; --i)
        printf("%d ", PreOrder[i]);
    puts("");

    free(InOrder);
    free(PreOrder);
    free(PostOrder);

    InOrder = PreOrder = PostOrder = NULL;
    sizeIn = sizePre = sizePost = -1;
    allocIn = allocPre = allocPost = 0;
    maximumIn = maximumPre = maximumPost = 0;
}


static void InOrderTMP(TREE **tracer)
{
    if(*tracer)
    {
        InOrderTMP(&(*tracer) -> left);
        Enqueue((*tracer) -> numar, &InOrder, &sizeIn, &allocIn, &maximumIn);
        InOrderTMP(&(*tracer) -> right);
    }
}

static void PreOrderTMP(TREE **tracer)
{
    if(*tracer)
    {
        Enqueue((*tracer) -> numar, &PreOrder, &sizePre, &allocPre, &maximumPre);
        PreOrderTMP(&(*tracer) -> left);
        PreOrderTMP(&(*tracer) -> right);
    }
}

static void PostOrderTMP(int start, int end)
{
    if (start > end)    return;

    int numar = PreOrder[headPreTemp++];

    if (start == end)
    {
        Enqueue(numar, &PostOrder, &sizePost, &allocPost, &maximumPost);
        
        return;
    }

    int index = SearchIn(numar);

    PostOrderTMP(start, index-1);
    PostOrderTMP(index+1, end);

    Enqueue(numar, &PostOrder, &sizePost, &allocPost, &maximumPost);
}

static void InOrderPreOrder()
{
    InOrderTMP(&head);
    PreOrderTMP(&head);

    PostOrderTMP(0, sizeIn);

    printf("\nInOrder:\n");
    for(int i=0; i<=sizeIn; ++i)
        printf("%d ", InOrder[i]);
    puts("");

    printf("\nPreOrder:\n");
    for(int i=0; i<=sizePre; ++i)
        printf("%d ", PreOrder[i]);
    puts("");
    
    printf("\nPostOrder from InOrder & PreOrder:\n");
    for(int i=0; i<=sizePost; ++i)
        printf("%d ", PostOrder[i]);
    puts("");

    free(InOrder);
    free(PreOrder);
    free(PostOrder);

    InOrder = PreOrder = PostOrder = NULL;
    sizeIn = sizePre = sizePost = -1;
    allocIn = allocPre = allocPost = 0;
    maximumIn = maximumPre = maximumPost = 0;
    headPreTemp = 0;
}

static void Return(TREE **tracer)
{
    if (*tracer)
    {
        Return(&(*tracer) -> left);
        Return(&(*tracer) -> right);
        free(*tracer);
    }
}

void ControlTreeOE(int option)
{
    time_t t;
    srand((unsigned) time(&t));

    switch (option)
    {
        case 1:
            CreateTree();
            break;
        case 2:
            InOrderPostOrder();
            break;
        case 3:
            InOrderPreOrder();
            break;
        case 4:
            Return(&head);
            head = NULL;
            break;
        default:
            printf("\nSomething went Wrong with ControlTreeOE!\n");
            break;
    }
}