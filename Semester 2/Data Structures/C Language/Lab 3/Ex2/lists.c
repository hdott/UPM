#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persons.h"
#include "menu.h"



typedef struct lista
{
    char *nume;
    PERSON *head;
    struct lista *next;
} LIST;

LIST *listStart = NULL;


LIST *NewList(char *nume, PERSON *headPersons)
{
    LIST *newp = (LIST*) malloc(sizeof(LIST));

    newp -> nume = (char*) malloc(strlen(nume)+1);
        strcpy(newp -> nume, nume);

    newp -> head = headPersons;
    newp -> next = NULL;

    return newp;
}



static void InsertNewList(LIST **head, LIST *newp)
{
    LIST **tracer = head;

    if(!(*tracer))  *tracer = newp;
    else
    {
        while(*tracer && strcmp((*tracer) -> nume, newp -> nume) < 1)
            tracer = &(*tracer) -> next;

        newp -> next = *tracer;
        *tracer = newp;
    }
}

static _Bool IsListPresent(char *nume)
{
    LIST **tracer = &listStart;

    if(!(*tracer))  return 0;
    else
    {
        while(*tracer)
        {
            if(*tracer && !strcmp((*tracer) -> nume, nume)) return 1;

            tracer = &(*tracer) -> next;
        }

        return 0;
    }
}

static _Bool PrintListOfListsToFile()
{
    LIST **tracer = &listStart;

    FILE *list = fopen("lists.txt", "w");

    if(!(*tracer))
    {
        fclose(list);
        return 0;
    }
    else
    {
        while(*tracer)
        {
            fprintf(list, "%s\n", (*tracer) -> nume);
            
            tracer = &(*tracer) -> next;
        }

        fclose(list);
        return 1;
    }
}

static void SaveList(char *nume)
{
    char ch;
    checkIfSaved = 1;

    if(!IsListPresent(nume))
    {
        InsertNewList(&listStart, NewList(nume, personStart));

        PrintListOfListsToFile();
    }

    if(!PrintListToFile(nume) && !PrintListOfListsToFile())
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6) :
                        exit(1);
    }
    else
    {
        system("clear");
        getchar();
        printf("Lista a fost Salvata cu Succes!\n");
    }
}


static void RemoveList(LIST **head, char *nume)
{
    char ch;
    LIST *_toRemove;
    LIST **tracer = head;
    _Bool present = 0;
    
    if(!(*tracer))
    {
        system("clear");
        getchar();
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6) :
                        exit(1);
    }
    else if(!strcmp((*tracer) -> nume, nume))
    {
        MainPersons(&(*tracer) -> head, NULL, NULL, -1, 7, -1, NULL);

        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove -> nume);
        free(_toRemove);        
    }
    else
    {
        system("clear");
        while((*tracer) -> next && strcmp((*tracer) -> next -> nume, nume) != 0)
            tracer = &(*tracer) -> next;

        if((*tracer) -> next && strcmp((*tracer) -> next -> nume, nume) != 0)
        {
            MainPersons(&(*tracer) -> next -> head, NULL, NULL, -1, 7, -1, NULL);

            _toRemove = (*tracer) -> next;
            (*tracer) -> next = (*tracer) -> next -> next;
            
            present = 1;

            free(_toRemove -> nume);
            free(_toRemove);
        }

        if(!present)
        {
            printf("Lista nu a fost gasita!\n");
            printf("\nReintoarcere la meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(6)  :
                            exit(1);
        }
    }
}


static void SearchListKey(LIST **head, char *nume)
{
    LIST **tracer = head;
    char ch;
    _Bool present = 0, conditie = 0;

    if(!(*tracer))
    {
        getchar();
        printf("\nLista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6) :
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
                printf("%s\n", ((*tracer) -> nume));

            tracer = &(*tracer) -> next;
        }

        if(!present)
        {
            getchar();
            printf("Lista cu numele \"%s\" NU exista!\n", nume);
            printf("\nReintoarcere la meniul anterior?\n");
                printf("(y/n): "), scanf("%c", &ch);

            (ch == 'y') ?   menu(6) :
                            exit(1);
        }
    }
}


static void PrintListPersons(LIST ** head)
{
    LIST **tracer = head;
    char ch;

    if(!(*tracer))
    {
        system("clear");
        printf("Lista este goala! Reintoarcere la meniul anterior?\n");
            printf("(y/n): "), scanf("%c", &ch);

        (ch == 'y') ?   menu(6)  :
                        exit(1);
    } 
    else if(*tracer)
    {
        system("clear");
        printf("Listele sunt:\n\n");

        while(*tracer)
        {
            printf("%s\n", ((*tracer) -> nume));

            tracer = &(*tracer) -> next;
        }
    }
    else    puts("ERROR in PrintListPersons Function!");
}


void MainLists(LIST **head, char *nume, int option, LIST *newp)
{
    switch(option)
    {
        case 1:
            SaveList(nume);
            break;
        case 2:
            RemoveList(head, nume);
            break;
        case 3:
            SearchListKey(head, nume);
            break;
        case 4:
            PrintListPersons(head);
            break;
        case 5:
            InsertNewList(head, newp);
            break;
        default:
            puts("ERROR in MainLists Function!\n");
            break;
    }
}