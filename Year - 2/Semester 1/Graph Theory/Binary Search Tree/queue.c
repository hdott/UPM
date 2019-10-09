#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


typedef struct coada {
    TREE *arb;
    struct coada *next;
} QUEUE;


QUEUE *NewQueue (TREE *arb) {
    QUEUE *newp = (QUEUE*) malloc(sizeof(QUEUE));

    newp->arb = arb;
    newp->next = NULL;

    return newp;
}

int Enqueue (QUEUE *head, QUEUE *tail, QUEUE *newp) {
    if (!head) {
        head = tail = newp;

        return 1;
    } else {
        tail->next = newp;
        tail = newp;

        return 1;
    }

    return 0;
}

int Dequeue (QUEUE *head) {
    if (!head)  return 0;
    else {
        PrintNode(head->arb);
        
        QUEUE *_toRemove = head;
        head = head->next;

        free(_toRemove);
        return 1;
    }
}

int IsEmptyQueue (QUEUE *head) {
    if (!head)  return 1;
    else    return 0;
}

TREE *GetFirstNode (QUEUE *head) {
    return head->arb;
}