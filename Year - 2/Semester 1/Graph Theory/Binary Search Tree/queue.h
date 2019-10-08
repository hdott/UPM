#include "bst.h"

typedef struct coada QUEUE;

QUEUE *NewQueue (TREE *arb);
int Enqueue (QUEUE *head, QUEUE *tail, QUEUE *newp);
int Dequeue (QUEUE *head);
int IsEmptyQueue (QUEUE *head);
TREE *GetFirstNode (QUEUE *head);