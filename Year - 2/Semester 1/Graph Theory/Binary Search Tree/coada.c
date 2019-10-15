#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


typedef struct nod_coada{
    BST *arb;
    struct nod_coada *next;
} QUEUE;


QUEUE *NewNodeQueue(BST *arb){
    QUEUE *newp = (QUEUE*) malloc(sizeof(QUEUE));

    newp->arb = arb;
    newp->next = NULL;

    return newp;
}


QUEUE *queue_head = NULL;
QUEUE *queue_tail = NULL;


void Enqueue(QUEUE *newp){
    if(!queue_head){
        queue_head = queue_tail = newp;
    } else{
        queue_tail = queue_tail->next = newp;
    }
}

BST *Dequeue(){
    if(queue_head){
        QUEUE *_toRemove = queue_head;
        BST *_tmp = queue_head->arb;
        queue_head = queue_head->next;

        free(_toRemove);
        return _tmp;
    } else{
        return NULL;
    }
}

int QueueIsEmpty(){
    if(queue_head){
        return 0;
    } else{
        return 1;
    }
}