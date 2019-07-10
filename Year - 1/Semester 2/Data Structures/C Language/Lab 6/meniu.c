#include <stdio.h>
#include <stdlib.h>
#include "coadaStatica.h"
#include "coadaDinamica.h"
#include "coadaStaticaOE.h"
#include "coadaDinamicaLSI.h"
#include "coadaDinamicaLDI.h"
#include "meniu.h"
#define MAXL 50
#define MAXP 2
#define MAXOB 3
#define MAXOE 4
#define MAXS 4
#define MAXSE 14


static char meniuPrincipal[][MAXL] = {"1. Operatii de baza", "2. Operatii extinse"};
static char meniuOB[][MAXL] = {"1. Coada - implementare statica",
                            "2. Coada - implementare dinamica", "3. Return"};
static char meniuOE[][MAXL] = {"1. Coada - implementare statica",
                            "2. Coada - implementare dinamica cu LSI",
                            "3. Coada - implementare dinamica cu LDI", "4. Return"};
static char meniuSecundar[][MAXL] = {"1. Enqueue", "2. Dequeue", "3. Clear", "4. Return"};


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


static void CreateSerie(long unsigned temp, unsigned serie[])
{
    for(int i=0; i<MAXSE; ++i, temp /= 10)
        serie[i] = temp % 10;

    for(int i=0, j=MAXSE-1; i<MAXSE/2; ++i, --j)
    {
        unsigned aux = serie[i];
        serie[i] = serie[j];
        serie[j] = aux;
    }
}

static void CoadaStatica()
{
    system("clear");
    for (int i=0; i<MAXS; ++i)
        printf("%s\n", meniuSecundar[i]);

    char nume[MAXL], prenume[MAXL];
    long unsigned temp;
    unsigned serie[MAXSE];

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Enqueue -\n");
                printf("(nume prenume serie): ");
                    scanf("%s %s %lu", nume, prenume, &temp);
                    getchar();

                CreateSerie(temp, serie);
                ControlCoadaStatica(1, nume, prenume, serie);
            } while (ReturnOrContinue() != '0');

            return CoadaStatica();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Dequeue -\n");

                ControlCoadaStatica(2, NULL, NULL, NULL);
            } while (ReturnOrContinue() != '0');

            return CoadaStatica();
            break;
        case 3:
            system("clear");
            printf("- Clear -\n");

            ControlCoadaStatica(3, NULL, NULL, NULL);
            
            ReturnToPrev();
            return CoadaStatica();
            break;
        case 4:
            ControlMeniu(1, 0);
            break;
        default:
            printf("\nSomething went Wrong with CoadaStatica!\n");
            break;
    }
}

static void CoadaDinamica()
{
    system("clear");
    for (int i=0; i<MAXS; ++i)
        printf("%s\n", meniuSecundar[i]);

    char nume[MAXL], prenume[MAXL];
    long unsigned temp;
    unsigned serie[MAXSE];

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Enqueue -\n");
                printf("(nume prenume serie): ");
                    scanf("%s %s %lu", nume, prenume, &temp);
                    getchar();
                
                CreateSerie(temp, serie);
                ControlCoadaDinamica(1, nume, prenume, serie);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamica();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Dequeue -\n");

                ControlCoadaDinamica(2, NULL, NULL, NULL);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamica();
            break;
        case 3:
            system("clear");
            printf("- Clear -\n");

            ControlCoadaDinamica(3, NULL, NULL, NULL);

            ReturnToPrev();
            return CoadaDinamica();
            break;
        case 4:
            ControlMeniu(1, 0);
            break;
        default:
            printf("\nSomething went Wrong with CoadaStatica!\n");
            break;
    }
}

static void MeniuOB(int option)
{
    system("clear");
    if(!option)
    {
        for(int i=0; i<MAXOB; ++i)
            printf("%s\n", meniuOB[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            CoadaStatica();
            break;
        case 2:
            CoadaDinamica();
            break;
        case 3:
            ControlMeniu(0, 0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuOB!\n");
            break;
    }
}


static void CoadaStaticaOE()
{
    system("clear");
    for (int i=0; i<MAXS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Enqueue -\n");

                ControlCoadaStaticaOE(1);
            } while (ReturnOrContinue() != '0');

            return CoadaStaticaOE();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Dequeue -\n");

                ControlCoadaStaticaOE(2);
            } while (ReturnOrContinue() != '0');

            return CoadaStaticaOE();
            break;
        case 3:
            system("clear");
            printf("- Clear -\n");

            ControlCoadaStaticaOE(3);

            ReturnToPrev();
            return CoadaStaticaOE();
            break;
        case 4:
            ControlMeniu(2, 0);
            break;
        default:
            printf("\nSomething went Wrong with CoadaStaticaOE!\n");
            break;
    }
}

static void CoadaDinamicaLSI()
{
    system("clear");
    for (int i=0; i<MAXS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Enqueue -\n");

                ControlCoadaDinamicaLSI(1);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamicaLSI();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Dequeue -\n");

                ControlCoadaDinamicaLSI(2);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamicaLSI();
            break;
        case 3:
            system("clear");
            printf("- Clear -\n");

            ControlCoadaDinamicaLSI(3);

            ReturnToPrev();
            return CoadaDinamicaLSI();
            break;
        case 4:
            ControlMeniu(2, 0);
            break;
        default:
            printf("\nSomething went Wrong with CoadaDinamicaLSI!\n");
            break;
    }
}

static void CoadaDinamicaLDI()
{
    system("clear");
    for (int i=0; i<MAXS; ++i)
        printf("%s\n", meniuSecundar[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Enqueue -\n");

                ControlCoadaDinamicaLDI(1);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamicaLDI();
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Dequeue -\n");

                ControlCoadaDinamicaLDI(2);
            } while (ReturnOrContinue() != '0');

            return CoadaDinamicaLDI();
            break;
        case 3:
            system("clear");
            printf("- Clear -\n");

            ControlCoadaDinamicaLDI(3);

            ReturnToPrev();
            return CoadaDinamicaLDI();
            break;
        case 4:
            ControlMeniu(2, 0);
            break;
        default:
            printf("\nSomething went Wrong with CoadaDinamicaLDI!\n");
            break;
    }
}

static void MeniuOE(int option)
{
    system("clear");
    if(!option)
    {
        for (int i=0; i<MAXOE; ++i)
            printf("%s\n", meniuOE[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            CoadaStaticaOE();
            break;
        case 2:
            CoadaDinamicaLSI();
            break;
        case 3:
            CoadaDinamicaLDI();
            break;
        case 4:
            ControlMeniu(0, 0);
            break;
        default:
            printf("\nSomething went Wrong with MeniuOE!\n");
            break;
    }
}


void ControlMeniu(int option1, int option2)
{
    system("clear");
    if(!option1)
    {
        for(int i=0; i<MAXP; ++i)
            printf("%s\n", meniuPrincipal[i]);


        option1 = AlegeOptiune();
    }

    switch (option1)
    {
        case 1:
            MeniuOB(option2);
            break;
        case 2:
            MeniuOE(option2);
            break;
        default:
            printf("\nSomething went Wrong with ControlMeniu!\n");
            break;
    }
}