#include <stdio.h>
#include <stdlib.h>
#include "operatiiBaza.h"
#include "operatiiExtinse.h"
#include "meniu.h"
#define MAXL 100
#define MAXPS 3
#define MAXOB 11
#define MAXOE 5

static char meniuPrincipal[][MAXL] = {"1. Operatii de baza", "2. Operatii extinse",
                                    "3. Exit"};
static char meniuOperatiiBaza[][MAXL] = {"1. Inserare", "2. Traversare InOrdine",
                                    "3. Traversare PreOrdine", "4. Traversare PostOrdine",
                                    "5. Cautare", "6. Distrugere",
                                    "7. Determinarea adancimii maxime a Arborelui",
                                    "8. Determinarea tuturor nodurilor aflate pe un nivel dat",
                                    "9. Egalitatea structurala a doi arbori", "10. Return",
                                    "11. Exit"};
static char meniuOperatiiExtinse[][MAXL] = {"1. Inserare automata",
                                    "2. Crearea Succesiunii PreOrdine din InOrdine & PostOrdine",
                                    "3. Crearea Succesiunii PostOrdine din InOrdine & PreOrdine",
                                    "4. Return", "5. Exit"};
static char meniuSecundar[][MAXL] = {"1. Arbore-1", "2. Arbore-2", "3. Return"};


static int AlegeOptiune()
{
    int opt;
    printf("\nAlegeti Optiunea: ");
    scanf("%d", &opt);
    getchar();

    return opt;
}

static char ReturnOrContinue()
{
    char roc;
    printf("\nEnter to Repeat, 0 to Return... ");
    scanf("%c", &roc);

    if(roc != '\n') getchar();

    return roc;
}

static void ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();
}

static void MeniuSecundarInsert()
{
    int numar;
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Inserare Arbore-1 -\n\n");
                printf("(int): ");
                scanf("%d", &numar);
                getchar();

                ControlTree(1, -1, -1, &head, NewElement(numar));

                printf("Numarul a fost adaugat cu Success!\n");
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarInsert();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Inserare Arbore-2 -\n\n");
                printf("(int): ");
                scanf("%d", &numar);
                getchar();

                ControlTree(1, -1, -1, &head1, NewElement(numar));

                printf("Numarul a fost adaugat cu Success!\n");
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarInsert();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarInsert!\n");
            break;
    }
}

static void MeniuSecundarInOrder()
{
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Afisare InOrdine Abore-1 -\n\n");

            ControlTree(2, -1, -1, &head, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 2:
            system("clear");
            printf("- Afisare InOrdine Abore-2 -\n\n");

            ControlTree(2, -1, -1, &head1, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarInOrder!\n");
            break;
    }
}

static void MeniuSecundarPreOrder()
{
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Afisare PreOrdine Abore-1 -\n\n");

            ControlTree(3, -1, -1, &head, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 2:
            system("clear");
            printf("- Afisare PreOrdine Abore-2 -\n\n");

            ControlTree(3, -1, -1, &head1, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarPreOrder!\n");
            break;
    }
}

static void MeniuSecundarPostOrder()
{
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Afisare PostOrdine Abore-1 -\n\n");

            ControlTree(4, -1, -1, &head, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 2:
            system("clear");
            printf("- Afisare PostOrdine Abore-2 -\n\n");

            ControlTree(4, -1, -1, &head1, NULL);
            puts("");

            ReturnToPrev();
            return MeniuSecundarInOrder();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarPostOrder!\n");
            break;
    }
}

static void MeniuSecundarSearch()
{
    int numar;
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Cautare Arbore-1 -\n\n");
                printf("(int): ");
                scanf("%d", &numar);
                getchar();

                ControlTree(5, numar, -1, &head, NULL);
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarSearch();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Cautare Arbore-2 -\n\n");
                printf("(int): ");
                scanf("%d", &numar);
                getchar();

                ControlTree(5, numar, -1, &head1, NULL);
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarSearch();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarSearch!\n");
            break;
    }
}

static void MeniuSecundarDelete()
{
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Stergere Arbore-1 -\n\n");

            ControlTree(6, -1, -1, &head, NULL);

            ReturnToPrev();
            return MeniuSecundarDelete();
            break;
        case 2:
            system("clear");
            printf("- Stergere Arbore-2 -\n\n");

            ControlTree(6, -1, -1, &head1, NULL);

            ReturnToPrev();
            return MeniuSecundarDelete();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarDelete!\n");
            break;
    }
}

static void MeniuSecundarHeight()
{
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Adancimea Maxima a Arborelui-1 -\n\n");

            ControlTree(7, -1, -1, &head, NULL);

            ReturnToPrev();
            return MeniuSecundarHeight();
            break;
        case 2:
            system("clear");
            printf("- Adancimea Maxima a Arborelui-2 -\n\n");

            ControlTree(7, -1, -1, &head1, NULL);

            ReturnToPrev();
            return MeniuSecundarHeight();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarHeight!\n");
            break;
    }
}

static void MeniuSecundarNodesInLevel()
{
    int level;
    system("clear");
    for(int i=0; i<MAXPS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Determinarea tuturor nodurilor aflate pe un nivel Arbore-1 -\n\n");
                printf("(nivel): ");
                scanf("%d", &level);
                getchar();

                ControlTree(8, level, 0, &head, NULL);
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarNodesInLevel();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Determinarea tuturor nodurilor aflate pe un nivel Arbore-2 -\n\n");
                printf("(nivel): ");
                scanf("%d", &level);
                getchar();

                ControlTree(8, level, 0, &head1, NULL);
            } while (ReturnOrContinue() != '0');

            return MeniuSecundarNodesInLevel();
            break;
        case 3:
            ControlMeniu(1);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarNodesInLevel!\n");
            break;
    }
}

static void MeniuOperatiiBaza()
{
    system("clear");
    for(int i=0; i<MAXOB; ++i)
        printf("%s\n", meniuOperatiiBaza[i]);

    switch (AlegeOptiune())
    {
        case 1:
            MeniuSecundarInsert();
            break;
        case 2:
            MeniuSecundarInOrder();
            break;
        case 3:
            MeniuSecundarPreOrder();
            break;
        case 4:
            MeniuSecundarPostOrder();
            break;
        case 5:
            MeniuSecundarSearch();
            break;
        case 6:
            MeniuSecundarDelete();
            break;
        case 7:
            MeniuSecundarHeight();
            break;
        case 8:
            MeniuSecundarNodesInLevel();
            break;
        case 9:
            system("clear");
            printf("- Egalitatea structurala a doi Arbori -\n\n");

            ControlTree(9, -1, -1, NULL, NULL);

            return MeniuOperatiiBaza();
            break;
        case 10:
            ControlTree(10, -1, -1, NULL, NULL);

            ControlMeniu(0);
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuOperatiiBaza!\n");
            break;        
    }
}


static void MeniuOperatiiExtinse()
{
    system("clear");
    for(int i=0; i<MAXOE; ++i)
        printf("%s\n", meniuOperatiiExtinse[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Inserare Automata -\n\n");

            ControlTreeOE(1);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 2:
            system("clear");
            printf("- Crearea Succesiunii PreOrdine din InOrdine & PostOrdine -\n\n");

            ControlTreeOE(2);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 3:
            system("clear");
            printf("- Crearea Succesiunii PostOrdine din InOrdine & PreOrdine -\n\n");

            ControlTreeOE(3);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 4:
            ControlTreeOE(4);

            ControlMeniu(0);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuOperatiiExtinse!\n");
            break;
    }
}


void ControlMeniu(int option)
{
    system("clear");
    if(!option)
    {
        for(int i=0; i<MAXPS; ++i)
            printf("%s\n", meniuPrincipal[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            MeniuOperatiiBaza();
            break;
        case 2:
            MeniuOperatiiExtinse();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nSomething went Wrong with ControlMeniu!\n");
            break;
    }
}