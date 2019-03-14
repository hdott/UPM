#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

typedef struct persoana
{
    char *nume;
    char *prenume;
    int varsta;
    struct persoana *next;
} PERSON;

PERSON *personStart = NULL;


PERSON *NewPerson(char *nume, char *prenume, int varsta)
{
    PERSON *newp = (PERSON*) malloc(sizeof(PERSON));

    newp -> nume = (char*) malloc(strlen(nume)+1);
        strcpy(newp -> nume, nume);

    newp -> prenume = (char*) malloc(strlen(prenume)+1);
        strcpy(newp -> prenume, prenume);

    newp -> varsta = varsta;
    newp -> next = NULL;

    return newp;
}



// Insert functions
static void InsertPersonStart(PERSON **head, PERSON *newp)
{
    PERSON **tracer = head;

    if(!(*tracer))  *tracer = newp;
    else
    {
        newp -> next = *tracer;
        *tracer = newp;
    }
}

static void InsertPersonEnd(PERSON **head, PERSON *newp)
{
    PERSON **tracer = head;

    if(!(*tracer))  *tracer = newp;
    else
    {
        while(*tracer)    tracer = &(*tracer) -> next;

        *tracer = newp;
    }
}

static void InsertPersonBefore(PERSON **head, PERSON *newp, char *nume)
{
    PERSON **tracer = head;
    char ch;
    _Bool present = 0;

    if(!(*tracer))
    {
        getchar();
        puts("Lista este goala doriti sa introduceti persoana?");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   *tracer = newp  :
                        menu(1);
    }
    else if(!strcmp((*tracer) -> nume, nume))  
        InsertPersonStart(tracer, newp);
    else
    {
        while(((*tracer) -> next) && strcmp((*tracer) -> next -> nume, nume) != 0)
            tracer = &(*tracer) -> next;

        if((*tracer) -> next)
        {
            newp -> next = (*tracer) -> next;
           (*tracer) -> next = newp;

           present = 1;
        }

        if(!present)
        {
            getchar();
            puts("\nPersoana dorita nu a fost gasita in lista actuala!");
            puts("\nReintoarcere le meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(1)  :
                            exit(1);
        }
    }
}

static void InsertPersonAfter(PERSON **head, PERSON *newp, char *nume)
{
    PERSON **tracer = head;
    char ch;
    _Bool present = 0;
    
    if(!(*tracer))
    {
        getchar();
        puts("Lista este goala doriti sa introduceti persoana?");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   *tracer = newp  :
                        menu(1);
    }
    else
    {
        while(*tracer && strcmp((*tracer) -> nume, nume) != 0)
            tracer = &(*tracer) -> next;

        if((*tracer))
        {
            newp -> next = (*tracer) -> next;
            (*tracer) -> next = newp;

            present = 1;
        }

        if(!present)
        {
            getchar();
            puts("\nPersoana dorita nu a fost gasita in lista actuala!");
            puts("\nReintoarcere le meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(1)  :
                            exit(1);
        }
    }
}


// Remove functions
static void RemovePersonStart(PERSON **head)
{
    char ch;
    PERSON *_toRemove;
    PERSON **tracer = head;

    if(!(*tracer))
    {
        puts("\nLista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(2)  :
                        exit(1);
    }
    else if(*tracer)
    {
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove -> nume);
        free(_toRemove -> prenume);
        free(_toRemove);
    }
}

static void RemovePersonLast(PERSON **head)
{
    char ch;
    PERSON *_toRemove;
    PERSON **tracer = head;

    if(!(*tracer))
    {
        puts("\nLista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(2)  :
                        exit(1);
    }
    else if(*tracer)
    {
        while((*tracer) -> next)   tracer = &(*tracer) -> next;

        _toRemove = *tracer;
        *tracer = NULL;

        free(_toRemove -> nume);
        free(_toRemove -> prenume);
        free(_toRemove);
    }
}

static void RemovePersonKey(PERSON ** head, char *nume, char *prenume)
{
    char ch;
    PERSON *_toRemove;
    PERSON **tracer = head;
    _Bool present = 0;

    if(!(*tracer))
    {
        puts("\nLista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(2)  :
                        exit(1);
    }
    else if(!strcmp((*tracer) -> nume, nume) &&
        !strcmp((*tracer) -> prenume, prenume)) RemovePersonStart(tracer);
    else
    {
        system("clear");
        while((*tracer) -> next && 
                strcmp((*tracer) -> next -> nume, nume) != 0 &&
                strcmp((*tracer) -> next -> prenume, prenume) != 0)    
            tracer = &(*tracer) -> next;
    
        if((*tracer) -> next && 
                !strcmp((*tracer) -> next -> nume, nume) &&
                !strcmp((*tracer) -> next -> prenume, prenume))  
        {
            _toRemove = (*tracer) -> next;
            (*tracer) -> next = (*tracer) -> next -> next;
            
            present = 1;

            free(_toRemove -> nume);
            free(_toRemove -> prenume);
            free(_toRemove);
        }

        if(!present)
        {
            printf("Elementul nu a fost gasit in lista actuala!\n");
            printf("\nReintoarcere la meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(2)  :
                            exit(1);
        }
    }
}


// Search functions
static void SearchPersonName(PERSON **head, char *nume)
{
    PERSON **tracer = head;
    char ch;
    _Bool present = 0, conditie = 0;

    if(!(*tracer))  
    {
        getchar();
        printf("\nLista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(3)  :
                        exit(1);
    }
    else
    {   
        system("clear");
        while(*tracer)  
        {        
            if(*tracer && !strcmp((*tracer) -> nume, nume))
                present = 1;

            if(present && !conditie)
            {
                printf("S-au gasit urmatoarele rezultate:\n\n");
                conditie = 1;
            }
            
            if(present && conditie && !strcmp((*tracer) -> nume, nume))
            {
                printf("%s,%s%*d\n", (*tracer) -> nume,
                                        (*tracer) -> prenume,
                                        30 - strlen((*tracer) -> nume)
                                        - strlen((*tracer) -> prenume),
                                        (*tracer) -> varsta);
            }

            tracer = &(*tracer) -> next;
        }     
        
        if(!present)
        {
            getchar();
            printf("Numele \"%s\" NU a fost gasit in lista actuala!\n", nume);
            printf("\nReintoarcere le meniu anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(3)  :
                            exit(1);
        }
    }

}


static void SearchPersonSurname(PERSON **head, char *prenume)
{
    PERSON **tracer = head;
    char ch;
    _Bool present = 0, conditie = 0;

    if(!(*tracer))  
    {
        getchar();
        printf("Lista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(3)  :
                        exit(1);
    }
    else
    {   
        system("clear");
        while(*tracer)
        {
            if(*tracer && !strcmp((*tracer) -> prenume, prenume))
                present = 1;

            if(present && !conditie)
            {
                printf("S-au gasit urmatoarele rezultate:\n\n");
                conditie = 1;
            }
            
            if(present && conditie && !strcmp((*tracer) -> prenume, prenume))
            {
                printf("%s,%s%*d\n", (*tracer) -> nume,
                                        (*tracer) -> prenume,
                                        30 - strlen((*tracer) -> nume)
                                        - strlen((*tracer) -> prenume),
                                        (*tracer) -> varsta);
            }

            tracer = &(*tracer) -> next;
        }

        if(!present)
        {
            getchar();
            printf("Prenumele \"%s\" NU a fost gasit in lista actuala!\n", prenume);
            printf("Reintoarcere le meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(3)  :
                            exit(1);
        }
    }
}

static void SearchPersonAge(PERSON **head, int varsta)
{
    PERSON **tracer = head;
    char ch;
    _Bool present = 0, conditie = 0;

    if(!(*tracer))  
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(3)  :
                        exit(1);
    }
    else
    {   
        system("clear");
        while(*tracer)
        {
            if(*tracer && (*tracer) -> varsta == varsta)
                present = 1;

            if(present && !conditie)
            {
                printf("S-au gasit urmatoarele rezultate:\n\n");
                conditie = 1;
            }
            
            if(present && conditie && (*tracer) -> varsta == varsta)
            {
                printf("%s,%s%*d\n", (*tracer) -> nume,
                                        (*tracer) -> prenume,
                                        30 - strlen((*tracer) -> nume)
                                        - strlen((*tracer) -> prenume),
                                        (*tracer) -> varsta);
            }       

            tracer = &(*tracer) -> next; 
        }

        if(!present)
        {
            system("clear");
            getchar();
            printf("Varsta \"%d\" NU a fost gasit in lista actuala!\n", varsta);
            printf("Reintoarcere le meniu anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(3)  :
                            exit(1);
        }
    }
}


// Print List function
static void PrintListPersons(PERSON **head)
{
    PERSON **tracer = head;
    char ch;

    if(!(*tracer))  
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(0)  :
                        exit(1);
    }
    else if(*tracer)
    {
        system("clear");
        printf("Lista actuala este:\n\n");

        while(*tracer)
        {
            printf("%s,%s%*d\n", (*tracer) -> nume,
                                    (*tracer) -> prenume,
                                    30 - strlen((*tracer) -> nume)
                                    - strlen((*tracer) -> prenume),
                                    (*tracer) -> varsta);
            
            tracer = &(*tracer) -> next;
        }
    }
    else    puts("ERROR in PrintListPersons Function!");

    getchar();
    printf("\nReintoarcere le meniu anterior?\n");
        printf("(y/n): "), scanf("%c", &ch);
        
        (ch == 'y') ?   menu(0)  :
                        exit(1);
}


// Destroy List
static void RemoveWholeListPersons(PERSON **head)
{
    PERSON **tracer = head;
    PERSON *_toRemove;
    char ch;

    if(!(*tracer))  
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(0)  :
                        exit(1);
    }
    else if(*tracer)
    {
        while(*tracer)
        {
            _toRemove = *tracer;
            *tracer = (*tracer) -> next;

            free(_toRemove -> nume);
            free(_toRemove -> prenume);
            free(_toRemove);
        }

        system("clear");
        printf("Lista a fost stearsa!\n");
        getchar();
        printf("\nReintoarcere la meniu anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(0)  :
                        exit(1);
    }
    else    puts("ERROR in RemoveWholeListPersons function!");
}


// Control functions
static void InsertPersonsLink(PERSON **head, char *nume, int option,
                                PERSON *newp)
{
    switch(option)
    {
        case 1:
            InsertPersonStart(head, newp);
            break;
        case 2:
            InsertPersonEnd(head, newp);
            break;
        case 3:
            InsertPersonBefore(head, newp, nume);
            break;
        case 4:
            InsertPersonAfter(head, newp, nume);
            break;
        default:
            puts("ERROR in InsertPersonsLink Function!");
            break;
    }
}

static void RemovePersonsLink(PERSON **head, char *nume, char *prenume, int option,
                            PERSON *newp)
{
    switch(option)
    {
        case 1:
            RemovePersonStart(head);
            break;
        case 2:
            RemovePersonLast(head);
            break;
        case 3:
            RemovePersonKey(head, nume, prenume);
            break;
        default:
            puts("ERROR in RemovePersonsLink Function!");
            break;
    }
}

static void SearchPersonsLink(PERSON **head, char *nume, char *prenume, int varsta,
                                int option, PERSON *newp)
{
    switch(option)
    {
        case 1:
            SearchPersonName(head, nume);
            break;
        case 2:
            SearchPersonSurname(head, prenume);
            break;
        case 3:
            SearchPersonAge(head, varsta);
            break;
        default:
            puts("ERROR in SearchPersonsLink Function!");
            break;
    }
}

void MainPersons(PERSON **head, char *nume, char *prenume, int varsta,
                    int option1, int option2, PERSON *newp)
{
    switch(option1)
    {
        case 1:
            InsertPersonsLink(head, nume, option2, newp);
            break;
        case 2:
            RemovePersonsLink(head, nume, prenume, option2, newp);
            break;
        case 3:
            SearchPersonsLink(head, nume, prenume, varsta, option2, newp);
            break;
        case 4:
            PrintListPersons(head);
            break;
        case 5:
            RemoveWholeListPersons(head);
            break;
        default:
            puts("ERROR in MainPersons Function!\n");
            break;
    }
}