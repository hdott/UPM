#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


typedef struct stiva {
    TREE *arb;
    struct stiva *next;
} STACK;


STACK *NewStack (TREE *arb) {
    STACK *newp = (STACK*) malloc(sizeof(STACK));

    newp->arb = arb;
    newp->next = NULL;

    return newp;
}

int Push (STACK *tracer, STACK *newp) {
    if (!tracer) {
        tracer = newp;
        
        return 1;
    } 
    else {
        newp->next = tracer;
        tracer = newp;
        
        return 1;
    }

    return 0;
}

int Pop (STACK *tracer) {
    if (!tracer)    return 0;
    else {
        PrintNode(tracer->arb);
        
        STACK *_toRemove = tracer;
        tracer = tracer->next;

        free(_toRemove);
        return 1;
    }
}

int IsEmptyStack (STACK *tracer) {
    if (!tracer)    return 1;
    else    return 0;
}

TREE *GetArb (STACK *stk) { 
    return stk->arb;
}