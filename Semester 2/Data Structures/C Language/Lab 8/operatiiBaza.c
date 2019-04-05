#include <stdio.h>
#include <stdlib.h>


typedef struct arbore
{
    int numar;
    struct arbore *left;
    struct arbore *right;
} TREE;

TREE *head = NULL;
TREE *head1 = NULL;

TREE *NewElement(int numar)
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

static void Search(TREE **tracer, int numar)
{
    if (!(*tracer))
        printf("\nValoarea Nu a fost gasita!\n");
    else if((*tracer) -> numar == numar)
    {
        printf("\nValoarea a fost gasita!\n");
        printf("numarul -> %d\n", (*tracer) -> numar);
    }
    else
        if (numar < (*tracer) -> numar)
            Search(&(*tracer) -> left, numar);
        else
            Search(&(*tracer) -> right, numar);
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

static int Height(TREE **tracer)
{
    if (!(*tracer)) return 0;
    else
    {
        int _left = Height(&(*tracer) -> left);
        int _right = Height(&(*tracer) -> right);

        if(_left > _right)  return _left+1;
        else                return _right+1;
    }
}

static void NodesInLevel(TREE **tracer, int level, int *nodes)
{
    if(!(*tracer))              return;
    else if (!level)
    {
        ++(*nodes);
        return;
    }
    else
    {
        NodesInLevel(&(*tracer) -> left, level-1, nodes);
        NodesInLevel(&(*tracer) -> right, level-1, nodes);
    }
}

static int CheckEquality(TREE **tracer1, TREE **tracer2)
{
    if(!(*tracer1) && !(*tracer2))  return 1;

    if(*tracer1 && *tracer2)
        return ((*tracer1) -> numar == (*tracer2) -> numar &&
                CheckEquality(&(*tracer1) -> left, &(*tracer2) -> left) &&
                CheckEquality(&(*tracer1) -> right, &(*tracer2) -> right));

    return 0;
}

static void Return()
{
    if(!head)   Delete(&head);
    if(!head1)  Delete(&head1);
}

static void ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();
}

void ControlTree(int option, int numar_level, int counter, TREE **tracer, TREE *newp)
{
    int nodes = 0;

    switch (option)
    {
        case 1:
            Insert(tracer, newp);
            break;
        case 2:
            InOrder(tracer);
            break;
        case 3:
            PreOrder(tracer);
            break;
        case 4:
            PostOrder(tracer);
            break;
        case 5:
            Search(tracer, numar_level);
            break;
        case 6:
            Delete(tracer);
            break;
        case 7:
            printf("Adancimea Arborelui -> %d\n", Height(tracer));
            break;
        case 8:
            NodesInLevel(tracer, numar_level, &nodes);
            printf("Noduri in nivelul %d -> %d\n", numar_level, nodes);
            break;
        case 9:
            if(!head) printf("Arbore-1 este Gol!\n");
            if(!head1) printf("Arbore-2 este Gol!\n");
            else if(CheckEquality(&head, &head1))
                    printf("Arborii sunt Structural Egali!\n");
            else    printf("Arborii Nu sunt Structurali Egali!\n");
            
            ReturnToPrev();
            break;
        case 10:
            Return();
            break;
        default:
            printf("\nSomething went Wrong with ControlTree!\n");
            break;
    }
}