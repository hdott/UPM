#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


typedef struct nod_stiva{
    BST *nod_arb;
    struct nod_stiva *next;
} STACK;


STACK *NewNodeStack(BST *arb){
    STACK *newp = (STACK*) malloc(sizeof(STACK));

    newp->nod_arb = arb;
    newp->next = NULL;

    return newp;
}

static STACK *stack_head = NULL;


void Push(STACK *newp){
    if(!stack_head){
        stack_head = newp;
    } else{
        newp->next = stack_head;
        stack_head = newp;
    }
}

BST *Pop(){
    if(stack_head){
        STACK *_toRemove = stack_head;
        BST *_tmp = stack_head->nod_arb;
        stack_head = stack_head->next;
        
        free(_toRemove);
        return _tmp;
    } else{
        return NULL;
    }
}

int StackIsEmpty(){
    if(stack_head){
        return 0;
    } else{
        return 1;
    }
}