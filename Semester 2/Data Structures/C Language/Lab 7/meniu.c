#include <stdio.h>
#include <stdlib.h>
#include "operatiiBaza.h"
#include "operatiiExtinse.h"
#include "meniu.h"
#define MAXL 100
#define MAXP 3
#define MAXOB 5
#define MAXOE 6

static char meniuPrincipal[][MAXL] = {"1. Operatii de baza", "2. Operatii Extinse",
                                        "3. Exit"};
static char meniuOperatiiBaza[][MAXL] = {"1. Creare manuala a vectorului",
                                        "2. Generare automata a vectorului", "3. Afisare",
                                        "4. Cautare", "5. Return"};
static char meniuOperatiiExtinse[][MAXL] = {"1. Generare automata a doi vectori",
                    "2. Afisarea elementelor de pe pozitiile n/4, n/2 si n",
                    "3. Timpul de cautare comparativ al elementului aflat pe pozitia n/4",
                    "4. Timpul de cautare comparativ al elementului aflat pe pozitia n/2",
                    "5. Timpul de cautare comparativ al elementului aflat pe pozitia n",
                    "6. Return"};

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


static void MeniuOperatiiBaza()
{
    int temp;
    system("clear");
    for(int i=0; i<MAXOB; ++i)
        printf("%s\n", meniuOperatiiBaza[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Creare manuala a vectorului -\n");

            ControlOB(1, 0);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 2:
            system("clear");
            printf("- Generare automata a vectorului -\n");

            ControlOB(2, 0);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 3:
            system("clear");
            printf("- Afisare -\n");

            ControlOB(3, 0);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 4:
            do
            {
                system("clear");
                printf("- Cautare -\n");
                printf("(int): ");
                scanf("%d", &temp);
                getchar();

                ControlOB(4, temp);
            } while (ReturnOrContinue() != '0');
            
            return MeniuOperatiiBaza();
            break;
        case 5:
            ControlOB(5, 0);
            ControlMeniu(0);
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
            printf("- Generare automata a doi vectori -\n");

            ControlOE(1);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 2:
            system("clear");
            printf("- Afisara elementelor de pe pozitiile n/4, n/2 si n -\n");

            ControlOE(2);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 3:
            system("clear");
            printf("- Timpul de cautare comparativ al elementului aflat pe pozitia n/4 -\n");

            ControlOE(3);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 4:
            system("clear");
            printf("- Timpul de cautare comparativ al elementului aflat pe pozitia n/2 -\n");

            ControlOE(4);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 5:
            system("clear");
            printf("- Timpul de cautare comparativ al elementului aflat pe pozitia n -\n");

            ControlOE(5);

            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 6:
            ControlOE(6);
            ControlMeniu(0);
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
        for(int i=0; i<MAXP; ++i)
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