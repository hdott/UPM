#include <stdio.h>

typedef struct stiva STACK;

STACK *NewStack(char paranteza);

void ControlStack(int option, STACK *newp);