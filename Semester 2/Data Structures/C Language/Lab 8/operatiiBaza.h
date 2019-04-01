#include <stdio.h>

typedef struct copac TREE;

extern TREE *head;
extern TREE *head1;

TREE *NewElement(int numar);

void ControlTree(int option, int numar_level, int counter, TREE **tracer, TREE *newp);