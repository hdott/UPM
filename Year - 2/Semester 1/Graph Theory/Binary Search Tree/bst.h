#include "stack.h"

typedef struct arbore TREE;

TREE *NewElement (int numar, char *data);
int Insert (TREE *tracer, TREE *newp);
void InOrder (TREE *tracer);
void InOrder (TREE *tracer);
void PreOrder (TREE *tracer);
void PostOrder (TREE *tracer);
void PrintNode (TREE *tracer);
TREE *DeleteKey(TREE **tracer, int key);
int DeleteTree (TREE *tracer);
void InOrderWithStack (TREE *tracer, STACK *head);
