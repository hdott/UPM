#include "bst.h"

typedef struct nod_coada QUEUE;


QUEUE *NewNodeQueue(BST *arb);
void Enqueue(QUEUE *newp);
BST *Dequeue();
int QueueIsEmpty();