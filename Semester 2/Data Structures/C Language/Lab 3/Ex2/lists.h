#include <stdio.h>
#include "persons.h"

typedef struct lista LIST;

extern LIST *listStart;

LIST *NewList(char *nume, PERSON *headPersons);

void MainLists(LIST **head, char *nume, int option, LIST *newp);