#include <stdio.h>
#include <stdlib.h>



typedef struct lista
{
    char *nume;
    struct persoana *head;
    struct lista *next;
} LIST;

LIST *listStart = NULL;