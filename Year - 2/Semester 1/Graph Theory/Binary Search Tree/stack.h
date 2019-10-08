#include "bst.h"

typedef struct stiva STACK;

STACK *NewStack (TREE *arb);
int Push (STACK *tracer, STACK *newp);
int Pop (STACK *tracer);
int IsEmptyStack (STACK *tracer);
TREE *GetArb (STACK *stk);