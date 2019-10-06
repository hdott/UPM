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
        TREE *aux = tracer->arb;
        printf("%d - %s\n", aux->numar, aux->data);
    }
}