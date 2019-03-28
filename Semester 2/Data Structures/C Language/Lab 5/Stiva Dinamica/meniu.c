#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"
#define MAXL  30
#define MAXM 7

static char meniu[][MAXL] = {"1. Push", "2. Pop", "3. Peek", "4. Is Empty", "5. Clear",
                            "6. Verificare Expresie", "7. Exit"};

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

void Meniu(int option)
{
    char ch;

    if(!option)
    {
        system("clear");
        for(int i=0; i<MAXM; ++i)
            printf("%s\n", meniu[i]);

        option = AlegeOptiune();
    }

    switch (option)
    {
        case 1:
            do
            {
                system("clear");
                printf("- Push -\n\n");

                printf("(character): ");
                scanf("%c", &ch);
                getchar();
                puts("");

                ControlStack(1, NewStack(ch));      
            } while (ReturnOrContinue() != '0');

            return Meniu(0);
            break;
        case 2:
            do
            {
                system("clear");
                printf("- Pop -\n\n");
                
                ControlStack(2, NULL);
                puts("");
            } while (ReturnOrContinue() != '0');

            return Meniu(0);
            break;
        case 3:
            system("clear");
            printf("- Peek -\n\n");

            ControlStack(3, NULL);
            puts("");

            ReturnToPrev();
            return Meniu(0);
            break;
        case 4:
            system("clear");
            printf("- Is Empty -\n\n");

            ControlStack(4, NULL);
            puts("");

            ReturnToPrev();
            return Meniu(0);
            break;
        case 5:
            system("clear");
            printf("- Clear -\n\n");

            ControlStack(5, NULL);
            puts("");

            ReturnToPrev();
            return Meniu(0);
            break;
        case 6:
            system("clear");
            printf("- Verificare Expresie -\n\n");

            ControlStack(6, NULL);
            puts("");

            ReturnToPrev();
            return Meniu(0);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nSomething went Wrong with Meniu!\n");
            break;
    }
}