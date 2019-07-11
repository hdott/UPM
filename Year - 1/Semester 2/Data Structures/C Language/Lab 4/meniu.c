#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "meniu.h"
#define MAXL 60
#define MAXPrincipal 6
#define MAXAdaugare 5
#define MAXStergere 4
#define MAXAfisare 3
#define MAXOpExtinse 5


static char meniuPrincipal[][MAXL] = {"1. Adaugare", "2. Stergere", "3. Cautare",
                                    "4. Afisare", "5. Distrugere", "6. Operatii Extinse"};
static char meniuAdaugare[][MAXL] = {"1. La inceput", "2. La sfarsit", "3. Inaintea unui element",
                                    "4. Dupa un element", "5. Return"};
static char meniuStergere[][MAXL] = {"1. Primul element", "2. Ultimul element",
                                    "3. Element identificat", "4. Return"};
static char meniuAfisare[][MAXL] = {"1. Inceput-Sfarsit", "2. Sfarsit-Inceput", "3. Return"};
static char meniuOpExtinse[][MAXL] = {"1. Eliminarea elementelor care se repeta",
                                    "2. Adaugarea unui element dupa fiecare divizor al sau",
                                    "3. Ordonarea listei crescator",
                                    "4. Ordonarea listei descrescator", "5. Return"};


static int AlegeOptiune()
{
    int optiune;
    printf("\nAlegeti Optiunea: ");
        scanf("%d", &optiune);
    getchar();

    return optiune;
}

static char ContinueFork()
{
    char ch;
    printf("\nEnter pentru a continua 0 pentru a reveni la Meniul Anterior... ");
        scanf("%c", &ch);
    
    if(ch == '0')   getchar();

    return ch;
}

static void MeniuAdaugare()
{
    unsigned nr, key;
    system("clear");
    for(int i=0; i<MAXAdaugare; ++i)
        printf("%s\n", meniuAdaugare[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Adaugare La Inceput -\n\n");
                printf("(unsigned): ");
                scanf("%u", &nr);
                getchar();

                ControlLink(1, 1, 0, NewElement(nr));    
                printf("\nElementul a fost Adaugat cu Succes!\n");                
            } while (ContinueFork() != '0');
            
            return MeniuAdaugare();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Adaugare La Sfarsit -\n\n");
                printf("(unsigned): ");
                scanf("%u", &nr);
                getchar();

                ControlLink(1, 2, 0, NewElement(nr));
                printf("\nElementul a fost Adaugat cu Succes!\n");
            } while (ContinueFork() != '0');

            return MeniuAdaugare();
            break;
        case 3:
            do
            {
                system("clear");
                printf("- Adaugare Inaintea unui Element -\n\n");
                printf("(unsigned_element unsigned_cheie): ");
                scanf("%u %u", &nr, &key);
                getchar();

                ControlLink(1, 3, key, NewElement(nr));
                printf("\nElementul a fost Adaugat cu Succes!\n");
            } while (ContinueFork() != '0');

            return MeniuAdaugare();
            break;
        case 4:
            do
            {
                system("clear");
                printf("- Adaugare Dupa un Element -\n\n");
                printf("(unsigned_element unsigned_cheie): ");
                scanf("%u %u", &nr, &key);
                getchar();

                ControlLink(1, 4, key, NewElement(nr));
                printf("\nElementul a fost Adaugat cu Succes!\n");
            } while (ContinueFork() != '0');

            return MeniuAdaugare();
            break;
        case 5:
            MeniuPrincipal(0);
            break;
        default:
            printf("Something went Wrong with MeniuAdaugare!\n");
            break;
    } 
}

static void MeniuStergere()
{
    unsigned nr, key;
    system("clear");
    for(int i=0; i<MAXStergere; ++i)
        printf("%s\n", meniuStergere[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                ControlLink(2, 1, 0, NULL);
                printf("Primul Element a fost Sters cu Succes!\n");
            } while (ContinueFork() != '0');

            return MeniuStergere();
            break;
        case 2:
            do
            {
                system("clear");
                ControlLink(2, 2, 0, NULL);
                printf("Ultimul Element a fost Sters cu Succes!\n");
            } while (ContinueFork() != '0');

            return MeniuStergere();
            break;
        case 3:
            do
            {
                system("clear");
                printf("- Stergerea unui Element -\n\n");
                printf("(unsigned_cheie): ");
                scanf("%u", &key);
                getchar();

                ControlLink(2, 3, key, NULL);
                printf("Elementul a fost Sters cu Success!\n");
            } while (ContinueFork() != '0');

            return MeniuStergere();
            break;
        case 4:
            MeniuPrincipal(0);
            break;
        default:
            printf("Something went Wrong with MeniuStergere!\n");
            break;
    }
}

static void MeniuCautare()
{
    system("clear");
    unsigned key;

    printf("- Cautarea unui Element -\n\n");
    printf("(unsigned_cheie): ");
    scanf("%u", &key);

    ControlLink(3, 0, key, NULL);

    if(ContinueFork() == '\n')  return MeniuCautare();
    else                        MeniuPrincipal(0);   
}

static void MeniuAfisare()
{
    system("clear");
    for(int i=0; i<MAXAfisare; ++i)
        printf("%s\n", meniuAfisare[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Afisare Inceput-Sfarsit -\n\n");

                ControlLink(4, 1, 0, NULL);
            } while (ContinueFork() != '0');

            return MeniuAfisare();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Afisare Sfarsit-Inceput -\n\n");

                ControlLink(4, 2, 0, NULL);
            } while (ContinueFork() != '0');

            return MeniuAfisare();
            break;
        case 3:
            MeniuPrincipal(0);
            break;
        default:
            printf("Something went Wrong with MeniuAfisare!\n");
            break;
    }
}

static void MeniuDistrugere()
{
    system("clear");
    ControlLink(5, 0, 0, NULL);
    printf("Lista a fost Distrusa cu Success!\n");

    if(ContinueFork() == '\n')  return MeniuDistrugere();
    else                        MeniuPrincipal(0);
}

static void ContinueNotForked()
{
    printf("\nEnter pentru a continua...");
    getchar();
}

static void MeniuOpExtinse()
{
    unsigned nr;
    system("clear");
    for(int i=0; i<MAXOpExtinse; ++i)
        printf("%s\n", meniuOpExtinse[i]);

    switch(AlegeOptiune())
    {
        case 1:
            system("clear");
            ControlLink(6, 1, 0, NULL);
            printf("Duplicatele au fost Sterse cu Success!\n");

            ContinueNotForked();
            return MeniuOpExtinse();
            break;
        case 2:
            system("clear");
            printf("- Adaugarea unui Element dupa fiecare Divizor al sau -\n\n");
            printf("(unsigned): ");
            scanf("%u", &nr);
            getchar();
            
            ControlLink(6, 2, nr, NULL);

            ContinueNotForked();
            return MeniuOpExtinse();
            break;
        case 3:
            system("clear");
            
            ControlLink(6, 3, 0, NULL);
            printf("Lista a fost Ordonata Crescator cu Succes!\n\n");
            ControlLink(4, 1, 0, NULL);

            ContinueNotForked();
            return MeniuOpExtinse();
            break;
        case 4:
            system("clear");

            ControlLink(6, 4, 0, NULL);
            printf("Lista a fost Ordonata Descrescator cu Succes!\n\n");
            ControlLink(4, 1, 0, NULL);

            ContinueNotForked();
            return MeniuOpExtinse();
            break;
        case 5:
            MeniuPrincipal(0);
            break;
        default:
            printf("Something went Wrong with MeniuOpExtinse!\n");
            break;
    }
}

void MeniuPrincipal(int optiune)
{
    if(!optiune)
    {    
        system("clear");

        for(int i=0; i<MAXPrincipal; ++i)
            printf("%s\n", meniuPrincipal[i]);

        switch (AlegeOptiune())
        {
            case 1:
                MeniuAdaugare();
                break;
            case 2:
                MeniuStergere();
                break;
            case 3:
                MeniuCautare();
                break;
            case 4:
                MeniuAfisare();
                break;
            case 5:
                MeniuDistrugere();
                break;
            case 6:
                MeniuOpExtinse();
                break;
            default:
                printf("Something went Wrong with MeniuPrincipal!\n");
                break;
        }
    }
    else
        switch (optiune)
        {
            case 1:
                MeniuAdaugare();
                break;
            case 2:
                MeniuStergere();
                break;
            case 3:
                MeniuCautare();
                break;
            case 4:
                MeniuAfisare();
                break;
            case 5:
                MeniuDistrugere();
                break;
            case 6:
                MeniuOpExtinse();
                break;
            default:
                printf("Something went Wrong with MeniuPrincipal!\n");
                break;
        }
}