#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#define MAX 100

_Bool checkIfSaved = 1;

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

    checkIfSaved = 0;
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

    checkIfSaved = 0;
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

        (ch == 'y') ?   (*tracer = newp,
                        checkIfSaved = 0)  :
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

            checkIfSaved = 0;
        }

        if(!present)
        {
            getchar();
            puts("\nPersoana dorita nu a fost gasita in lista actuala!");
            puts("\nReintoarcere le meniull anterior?\n");
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

        (ch == 'y') ?   (*tracer = newp,
                        checkIfSaved = 0)  :
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

            checkIfSaved = 0;
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
        puts("\nLista este goala! Reintoarcere la  anterior?\n");
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


        checkIfSaved = 0;
    }
}

static void RemovePersonLast(PERSON **head)
{
    char ch;
    PERSON *_toRemove;
    PERSON **tracer = head;

    if(!(*tracer))
    {
        puts("\nLista este goala! Reintoarcere la  anterior?\n");
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

        checkIfSaved = 0;
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
        puts("\nLista este goala! Reintoarcere la meniul anterior?\n");
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

            checkIfSaved = 0;
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
        printf("\nLista este goala! Reintoarcere la meniul anterior?\n");
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
            printf("\nReintoarcere le meniul anterior?\n");
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
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
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
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
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
            printf("Reintoarcere le meniul anterior?\n");
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
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
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
    printf("\nReintoarcere le meniul anterior?\n");
        printf("(y/n): "), scanf("%c", &ch);
        
        (ch == 'y') ?   menu(0)  :
                        exit(1);
}

static const char txt[] = ".txt";
static const char folder[] = "./Lists/";

_Bool PrintListToFile(char *name)
{
    PERSON **tracer = &personStart;

    char output[MAX];
    strcpy(output, folder);
    strcat(output, name);
    strcat(output, txt);
    FILE *elements = fopen(output, "w");

    if(!(*tracer))  
    {
        fclose(elements);
        return 0;
    }
    else
    {
        while(*tracer)
        {
            fprintf(elements, "%s %s %d\n", (*tracer) -> nume,
                                            (*tracer) -> prenume,
                                            (*tracer) -> varsta);

            tracer = &(*tracer) -> next;
        }

        fclose(elements);
        return 1;
    }
}

static void LoadList(char *name)
{
    char nume[MAX], prenume[MAX], prevNume[MAX], prevPrenume[MAX];
    int varsta, prevVarsta;
    char output[MAX];
    strcpy(output, folder);
    strcat(output, name);
    strcat(output, txt);
    FILE *elements = fopen(output, "r");

    if(elements)
        while(!feof(elements))
        {
            fscanf(elements, "%s %s %d", nume, prenume, &varsta);

            if(!strcmp(prevNume, nume) && !strcmp(prevPrenume, prenume) &&
                prevVarsta == varsta)   break;

            InsertPersonEnd(&personStart, NewPerson(nume, prenume, varsta));

            strcpy(prevNume, nume);
            strcpy(prevPrenume, prenume);
            prevVarsta = varsta;
        }
    else    puts("ERROR Loading Selected List!\n");

    checkIfSaved = 1;
    fclose(elements);
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
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
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
        printf("\nReintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(0)  :
                        exit(1);
    }
    else    puts("ERROR in RemoveWholeListPersons function!");
}

static void RemoveWholeList(PERSON **head)
{
    PERSON *_toRemove;
    PERSON **tracer = head;

    while(*tracer)
    {
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove -> nume);
        free(_toRemove -> prenume);
        free(_toRemove);
    }
}



// Operations for the specific List
static void FindOldest(PERSON **head, char *nume)
{
    PERSON **tracer = head;
    char ch, tempNume[MAX], tempPrenume[MAX];
    int tempVarsta;
    _Bool present = 0, conditie = 0;

    if(!(*tracer))
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6)  :
                        exit(1);
    }
    else
    {
        while(*tracer)
        {
            if(!present && !strcmp((*tracer) -> nume, nume))
            {
                strcpy(tempNume, (*tracer) -> nume);
                strcpy(tempPrenume, (*tracer) -> prenume);
                tempVarsta = (*tracer) -> varsta;
                present = 1;
            }

            if(present && !strcmp((*tracer) -> nume, nume))
            {
                if(tempVarsta < (*tracer) -> varsta)
                {
                    strcpy(tempNume, (*tracer) -> nume);
                    strcpy(tempPrenume, (*tracer) -> prenume);
                    tempVarsta = (*tracer) -> varsta;
                }
            }

            tracer = &(*tracer) -> next;
        }

        if(!present)
        {
            getchar();
            printf("Numele \"%s\" NU a fost gasit in lista actuala!\n", nume);
            printf("\nReintoarcere le meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(6)  :
                            exit(1);
        }
        else
        {
            getchar();
            system("clear");
            printf("Cea mai in varsta persoana cu numele \"%s\" este:\n\n", nume);
                printf("%s,%s%*d\n", tempNume, tempPrenume,
                                        30 - strlen(tempNume) - strlen(tempPrenume),
                                        tempVarsta);
        }
    }
}



// Determine Most Frequent Name
typedef struct tempStruct
{
    char *name;
    int freq;
    struct tempStruct *next;
} TEMP;

TEMP *startOfTemp = NULL;

TEMP  *NewTemp(char *name)
{
    TEMP *newp = (TEMP*) malloc(sizeof(TEMP));

    newp -> name = (char*) malloc(strlen(name)+1);
        strcpy(newp -> name, name);

    newp -> freq = 1;
    newp -> next = NULL;

    return newp;
}

static void InsertTemp(TEMP **head, TEMP *newp)
{
    TEMP **tracer = head;

    if(!(*tracer))  *tracer = newp;
    else
    {
        while(*tracer)  tracer = &(*tracer) -> next;

        *tracer = newp;
    }
} 

static void RemoveWholeTemp()
{
    TEMP *_toRemove;
    TEMP **tracer = &startOfTemp;

    while(*tracer)
    {
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove -> name);
        free(_toRemove);
    }
}

static void DetermineMostFrequentName(PERSON **head)
{
    PERSON **tracer = head;
    TEMP **tracerTemp = &startOfTemp;
    char ch;
    _Bool present;

    if(!(*tracer))
    {
        getchar();
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6)  :
                        exit(1);
    }
    else
    {
        getchar();
        while(*tracer)
        {
            present = 0;

            if(!(*tracerTemp))
                InsertTemp(tracerTemp, NewTemp((*tracer) -> nume));
            else
            {
                tracerTemp = &startOfTemp;
                while(*tracerTemp && strcmp((*tracer) -> nume, (*tracerTemp) -> name) != 0)
                    tracerTemp = &(*tracerTemp) -> next;
                
                if(*tracerTemp && !strcmp((*tracer) -> nume, (*tracerTemp) -> name))  
                {
                    (*tracerTemp) -> freq += 1;
                    present = 1;
                }

                if(!present)
                    InsertTemp(&startOfTemp, NewTemp((*tracer) -> nume));
            }

            tracer = &(*tracer) -> next;
        }
    }

    tracerTemp = &startOfTemp;
    _Bool firstTime = 0;
    int tempFreq;

    while(*tracerTemp)
    {
        if(!firstTime)  
        {
            tempFreq = (*tracerTemp) -> freq;
            firstTime = 1;
        }
        else if(tempFreq < (*tracerTemp) -> freq)
            tempFreq = (*tracerTemp) -> freq;

        tracerTemp = &(*tracerTemp) -> next;
    }

    tracerTemp = &startOfTemp;
    
    printf("Cel mai frecvent nume este:\n\n");
    while(*tracerTemp)
    {
        if(tempFreq == (*tracerTemp) -> freq)
            printf("\"%s\" cu %d aparitii\n", (*tracerTemp) -> name,
                                                (*tracerTemp) -> freq);
        
        tracerTemp = &(*tracerTemp) -> next;
    }

    RemoveWholeTemp();

    printf("\nReintoarcere le meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(6)  :
                            exit(1);
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
        case 6:
            LoadList(nume);
            break;
        case 7:
            RemoveWholeList(head);
            break;
        case 8:
            FindOldest(head, nume);
            break;
        case 9:
            DetermineMostFrequentName(head);
            break;
        default:
            puts("ERROR in MainPersons Function!\n");
            break;
    }
}