#include "bst.h"

typedef struct nod_stiva STACK;

STACK *NewNodeStack(BST *arb);
void Push(STACK *newp);
BST *Pop();
int StackIsEmpty();