#include <stdio.h>

typedef struct person PERSON;

extern PERSON *personStart;

PERSON *NewPerson(char *nume, char *prenume, int varsta);

void MainPersons(PERSON **head, char *nume, char *prenume, int varsta,
                    int option1, int option2, PERSON *newp);
