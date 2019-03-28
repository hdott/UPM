#include <stdio.h>
#include <stdlib.h>
#include "ssu.h"
#include "sse.h"
#include "ssuOE.h"
#include "sseOE.h"
#include "meniu.h"
#define MAXL 50
#define MAXP 2
#define MAXS 3
#define MAXOB 4
#define MAXOE 10

static void MeniuSecundarOE(int option);
static void MeniuSecundarOB(int option);

static char meniuPrincipal[][MAXL] = {"1. Operatii de baza", "2. Operatii extinse"};
static char meniuSecundar[][MAXL] = {"1. Stiva Statica Uzuala",
                                    "2. Stiva Statica Extensibila", "3. Return"};
static char meniuOperatiiBaza[][MAXL] = {"1. Push", "2. Pop", "3. Clear", "4. Return"};
static char meniuOperatiiExtinse[][MAXL] = {"1. Push 1", "2. Push 2", "3. Pop 1",
                                "4. Pop 2", "5. Clear 1", "6. Clear 2",
                                "7. Generare Stiva 3", "8. Pop 3", "9. Clear 3",
                                "10. Return"};


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

static void MeniuSSUOB()
{
    unsigned element;

    system("clear");
    printf("- Stiva Statica Uzuala -\n\n");
    for(int i=0; i<MAXOB; ++i)
        printf("%s\n", meniuOperatiiBaza[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Push -\n\n");

                printf("(unsigned): ");
                scanf("%u", &element);
                getchar();
                puts("");

                ControlSSU(1, element);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOB();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Pop -\n\n");
                puts("");

                ControlSSU(2, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOB();
            break;
        case 3:
            system("clear");

            printf("- Clear -\n\n");
            puts("");

            ControlSSU(3, -1);
            ReturnToPrev();

            return MeniuSSUOB();
            break;
        case 4:
            MeniuSecundarOB(0);
            break;
        default:
            printf("\nSomethin went Wrong with MeniuSSUOB!\n");
            break;
    }
}

static void MeniuSSEOB()
{
    unsigned element;

    system("clear");
    printf("- Stiva Statica Extensibila -\n\n");
    for(int i=0; i<MAXOB; ++i)
        printf("%s\n", meniuOperatiiBaza[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Push -\n\n");

                printf("(unsigned): ");
                scanf("%u", &element);
                getchar();
                puts("");

                ControlSSE(1, element);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOB();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Pop -\n\n");
                puts("");

                ControlSSE(2, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOB();
            break;
        case 3:
            system("clear");

            printf("- Clear -\n\n");
            puts("");

            ControlSSE(3, -1);
            ReturnToPrev();

            return MeniuSSEOB();
            break;
        case 4:
            MeniuSecundarOB(0);
            break;
        default:
            printf("\nSomethin went Wrong with MeniuSSEOB!\n");
            break;
    }
}

static void MeniuSecundarOB(int option)
{
    if(!option)
    {
        system("clear");
        printf("- Operatii de Baza -\n\n");
        for(int i=0; i<MAXS; ++i)
            printf("%s\n", meniuSecundar[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            MeniuSSUOB();
            break;
        case 2:
            MeniuSSEOB();
            break;
        case 3:
            MeniuPrincipal(0, 0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarOB!\n");
            break;
    }
}


static void MeniuSSUOE()
{
    unsigned cod, cantitate;
    double pret;

    system("clear");
    printf("- Stiva Statica Uzuala -\n\n");
    for(int i=0; i<MAXOE; ++i)
        printf("%s\n", meniuOperatiiExtinse[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Push 1 -\n\n");

                printf("(unsigned_cod unsigned_cantitate): ");
                scanf("%u %u", &cod, &cantitate);
                getchar();
                puts("");

                ControlSSUOE(1, cod, cantitate, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOE();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Push 2 -\n\n");

                printf("(unsigned_cod double_pret): ");
                scanf("%u %lf", &cod, &pret);
                getchar();
                puts("");

                ControlSSUOE(2, cod, -1, pret);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOE();
            break;
        case 3:
            do
            {
                system("clear");
                printf("- Pop 1 -\n\n");
                puts("");

                ControlSSUOE(3, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOE();
            break;
        case 4:
            do
            {
                system("clear");
                printf("- Pop 2 -\n\n");
                puts("");

                ControlSSUOE(4, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOE();
            break;
        case 5:
            system("clear");

            printf("- Clear 1 -\n\n");
            puts("");

            ControlSSUOE(5, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSUOE();
            break;
        case 6:
            system("clear");

            printf("- Clear 2 -\n\n");
            puts("");

            ControlSSUOE(6, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSUOE();
            break;
        case 7:
            system("clear");

            printf("- Generare Stiva 3 -\n\n");
            puts("");

            ControlSSUOE(7, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSUOE();
            break;
        case 8:
            do
            {
                system("clear");
                printf("- Pop 3 -\n\n");
                puts("");

                ControlSSUOE(8, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSUOE();
            break;
        case 9:
            system("clear");

            printf("- Clear 3 -\n\n");
            puts("");

            ControlSSUOE(9, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSUOE();
            break;
        case 10:
            MeniuSecundarOE(0);
            break;
        default:
            printf("Something went Wrong with MeniuSSUOE!\n");
            break;
    }
}

static void MeniuSSEOE()
{
    unsigned cod, cantitate;
    double pret;

    system("clear");
    printf("- Stiva Statica Uzuala -\n\n");
    for(int i=0; i<MAXOE; ++i)
        printf("%s\n", meniuOperatiiExtinse[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Push 1 -\n\n");

                printf("(unsigned_cod unsigned_cantitate): ");
                scanf("%u %u", &cod, &cantitate);
                getchar();
                puts("");

                ControlSSEOE(1, cod, cantitate, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOE();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Push 2 -\n\n");

                printf("(unsigned_cod double_pret): ");
                scanf("%u %lf", &cod, &pret);
                getchar();
                puts("");

                ControlSSEOE(2, cod, -1, pret);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOE();
            break;
        case 3:
            do
            {
                system("clear");
                printf("- Pop 1 -\n\n");
                puts("");

                ControlSSEOE(3, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOE();
            break;
        case 4:
            do
            {
                system("clear");
                printf("- Pop 2 -\n\n");
                puts("");

                ControlSSEOE(4, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOE();
            break;
        case 5:
            system("clear");

            printf("- Clear 1 -\n\n");
            puts("");

            ControlSSEOE(5, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSEOE();
            break;
        case 6:
            system("clear");

            printf("- Clear 2 -\n\n");
            puts("");

            ControlSSEOE(6, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSEOE();
            break;
        case 7:
            system("clear");

            printf("- Generare Stiva 3 -\n\n");
            puts("");

            ControlSSEOE(7, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSEOE();
            break;
        case 8:
            do
            {
                system("clear");
                printf("- Pop 3 -\n\n");
                puts("");

                ControlSSEOE(8, -1, -1, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuSSEOE();
            break;
        case 9:
            system("clear");

            printf("- Clear 3 -\n\n");
            puts("");

            ControlSSEOE(9, -1, -1, -1);
            ReturnToPrev();

            return MeniuSSEOE();
            break;
        case 10:
            MeniuSecundarOE(0);
            break;
        default:
            printf("Something went Wrong with MeniuSSUOE!\n");
            break;
    }
}

static void MeniuSecundarOE(int option)
{
    if(!option)
    {
        system("clear");
        printf("- Operatii Extinse -\n\n");
        for(int i=0; i<MAXS; ++i)
            printf("%s\n", meniuSecundar[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            MeniuSSUOE();
            break;
        case 2:
            MeniuSSEOE();
            break;
        case 3:
            MeniuPrincipal(0, 0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuSecundarOB!\n");
            break;
    }
}

void MeniuPrincipal(int option1, int option2)
{
    system("clear");
    if (!option1)
    {
        for(int i=0; i<MAXP; ++i)
            printf("%s\n", meniuPrincipal[i]);
        
        option1 = AlegeOptiune();
    }

    switch (option1)
    {
        case 1:
            MeniuSecundarOB(option2);
            break;
        case 2:
            MeniuSecundarOE(option2);
            break;
        default:
            printf("\nSomething went Wrong with MeniuPrincipal!\n");
            break;
    }
}
