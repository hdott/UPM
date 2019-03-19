/*
 * Sa se implementeze urmatoarele operatii de baza ce pot fi selectate prin
 *  intermediul unui meniu principal si mai multe sub-meniuri.
 * - Adaugare
 *      - La inceput
 *      - La sfarsit
 *      - Inaintea unui element identificat prin nume(cheie)
 *      - Dupa un element identificat prin nume(cheie)
 * - Stergerea
 *      - Primului
 *      - Ultimului
 *      - Unui element identificat prin nume si prenume(cheie)
 * - Cautare
 *      - Dupa nume(cheie)
 *      - Dupa prenume(cheie)
 *      - Dupa varsta(cheie)
 * - Afisare
 * - Distrugere
 * Sa se adauge optiunea "Operatii extinse" la meniul principal ce va permite
 *  urmatoarele:
 * - Crearea unei liste de list pornind de la lista deja creata prin intermediul
 *      meniului precedent
 * - Fiecare element al listei principale va contine:
 *      - Nume
 *      - Adresa primului element din lista atasata(secundara)
 *      - Adresa urmatorului element din lista principala
 * - Operatiile ce trebuie implementate:
 *      - Determinarea persoanei cu varsta cea mai mare(pentru un nume dat)
 *      - Determinarea numelui ce apare cel mai frecvent
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "persons.h"
#include "lists.h"
#define MAX 100


static const char txt[] = ".txt";
static const char folder[] = "./Lists/";

// Initiate the Top List at Start Time
void InitializeListAtStart()
{

    FILE *list = fopen("lists.txt", "r");
    FILE *elements;
    char nameList[MAX], name[MAX], surname[MAX], output[MAX], prevNameList[MAX];
    char prevNamePerson[MAX], prevSurnamePerson[MAX];
    int age, prevAge;
    _Bool firstOccurrence = 0, present = 0;

    if(list)
    {
        while(!feof(list))
        {
            if(!firstOccurrence)
            {
                fscanf(list, "%s", nameList);
                strcpy(prevNameList, nameList);
                MainLists(&listStart, NULL, 5, NewList(nameList, personStart));

                strcpy(output, folder);
                strcat(output, nameList);
                strcat(output, txt);
                puts(nameList);

                elements = fopen(output, "r");
                if(elements)
                {
                    while(!feof(elements))
                    {
                        fscanf(elements, "%s %s %d", name, surname, &age);

                        if(!strcmp(prevNamePerson, name) && 
                            !strcmp(prevSurnamePerson, surname) && 
                            prevAge == age) break;

                        MainPersons(&personStart, NULL, NULL, -1, 1, 2,
                                    NewPerson(name, surname, age));
                        
                        strcpy(prevNamePerson, name);
                        strcpy(prevSurnamePerson, surname);
                        prevAge = age;
                    }
                }
                else    puts("ERROR Initializing List!\n");

                fclose(elements);
                firstOccurrence = 1;
            }
            else
            {
                fscanf(list, "%s", nameList);

                if(!strcmp(prevNameList, nameList)) break;

                strcpy(prevNameList, nameList);

                MainLists(&listStart, NULL, 5, NewList(nameList, NULL));
            }
        }
    }
    else    present = 1;

    if(!present)    fclose(list);

    checkIfSaved = 1;
}

int main(void)
{
    InitializeListAtStart();
    menu(0);

    return 0;
}
