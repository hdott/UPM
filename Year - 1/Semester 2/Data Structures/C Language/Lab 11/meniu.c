#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define MAXL 30
#define MAXP 6

static char meniuPrincipal[][MAXL] = {"1. Inserare Automata", "2. Afisare InOrdine",
                                    "3. Afisare PreOrdine", "4. Afisare PostOrdine",
                                    "5. Distrugere", "6. Exit"};

static int AlegeOptiune()
{
    int opt;
    printf("\nAlegeti Optiunea: ");
    scanf("%d", &opt);
    getchar();

    return opt;
}

// static char ReturnOrContinue()
// {
//     char roc;
//     printf("\nEnter to Repeat, 0 to Return... ");
//     scanf("%c", &roc);

//     if(roc != '\n') getchar();

//     return roc;
// }

static void ReturnToPrev()
{
    printf("\nEnter to Continue...");
    getchar();
}


void Meniu()
{
    system("clear");
    for(int i=0; i<MAXP; ++i)
        printf("%s\n" , meniuPrincipal[i]);

    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Inserare Automata -\n\n");

            ControlFunctions(1);

            ReturnToPrev();
            return Meniu();
            break;
        case 2:
            system("clear");
            printf("- Afisare InOrdine -\n\n");

            ControlFunctions(2);
            
            ReturnToPrev();
            return Meniu();
            break;
        case 3:
            system("clear");
            printf("- Afisare PreOrdine -\n\n");

            ControlFunctions(3);

            ReturnToPrev();
            return Meniu();
            break;
        case 4:
            system("clear");
            printf("- Afisare PostOrinde -\n\n");

            ControlFunctions(4);

            ReturnToPrev();
            return Meniu();
            break;
        case 5:
            system("clear");
            printf("- Distrugere -\n\n");

            ControlFunctions(5);

            printf("Arborele a fost Distrus cu Success!\n");

            ReturnToPrev();
            return Meniu();
            break;
        case 6:
            ControlFunctions(5);
            exit(0);
            break;
        default:
            printf("\nSomething went Wrong with Meniu!\n");
            break;
    }
}