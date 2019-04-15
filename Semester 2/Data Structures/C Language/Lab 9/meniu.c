#include <stdio.h>
#include <stdlib.h>
#include "operatiiBaza.h"
#include "operatiiExtinse.h"
#include "meniu.h"
#define MAXL 100
#define MAXP 3
#define MAXOB 10
#define MAXOE 4


static char meniuPrincipal[][MAXL] = {"1. Operatii de baza", "2. Operatii extinse",
                                        "3. Exit"};
static char meniuOperatiiBaza[][MAXL] = {"1. Inserare", "2. Traversare InOrdine",
                                "3. Stergere", "4. Actualizare", "5. Distrugere",
                                "6. Stergerea Frunzelor Curente (cu afisare)",
                                "7. Stergerea Nodurilor de la Un Nivel Citit de la Tastatura",
                                "8. Inserare Automata", "9. Return", "10. Exit"};
static char meniuOperatiiExtinse[][MAXL] = {"1. Evaluarea expresiilor aritmetice",
                                    "2. Arbori de Expresie", "3. Return", "4. Exit"};

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
    int nr, nrToDelete;

    system("clear");
    for(int i=0; i<MAXOB; ++i)
        printf("%s\n", meniuOperatiiBaza[i]);

    switch (AlegeOptiune())
    {
        case 1:
            do
            {
                system("clear");
                printf("- Inserare -\n\n");
                printf("(int): ");
                scanf("%d", &nr);
                getchar();

                ControlOB(1, nr, -1);            
            } while (ReturnOrContinue() != '0');

            return MeniuOperatiiBaza();
            break;
        case 2:
            system("clear");
            printf("- Traversare InOrdine -\n\n");

            ControlOB(2, -1, -1);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 3:
            do
            {
                system("clear");
                printf("- Stergere -\n\n");
                printf("(int): ");
                scanf("%d", &nr);
                getchar();

                ControlOB(3, nr, -1);
            } while (ReturnOrContinue() != '0');

            return MeniuOperatiiBaza();
            break;
        case 4:
            do
            {
                system("clear");
                printf("- Actualizare -\n\n");
                printf("(nrToBeReplaced): ");
                scanf("%d", &nrToDelete);
                getchar();
                printf("(newNumber): ");
                scanf("%d", &nr);
                getchar();

                ControlOB(4, nr, nrToDelete);
            } while (ReturnOrContinue() != '0');

            return MeniuOperatiiBaza();
            break;
        case 5:
            system("clear");
            
            ControlOB(5, -1, -1);
            printf("Arborele a fost Sters cu Success!\n\n");

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 6:
            system("clear");
            printf("- Stergerea Frunzelor Curente -\n\n");
            
            ControlOB(6, -1, -1);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 7:
            system("clear");
            printf("- Stergerea Nodurilor de la Un Nivel Dat -\n\n");

            printf("(level): ");
            scanf("%d", &nr);
            getchar();

            ControlOB(7, nr, -1);

            printf("Nivelul a fost Sters cu Success!\n");

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 8:
            system("clear");
            printf("- Inserare Automata -\n\n");

            printf("(size): ");
            scanf("%d", &nr);
            getchar();

            ControlOB(8, nr, -1);

            ReturnToPrev();
            return MeniuOperatiiBaza();
            break;
        case 9:
            meniu();
            break;
        case 10:
            exit(0);
            return;
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

    char *expresie = (char*) malloc(MAXL);
    int index=0;
    switch (AlegeOptiune())
    {
        case 1:
            system("clear");
            printf("- Evaluarea expressilor aritmetice -\n\n");

            printf("(expresie): ");
            fgets(expresie, MAXL, stdin);
            while(expresie[index] != '\n')  ++index;
            expresie[index] = '\0';

            ControlOE(1, expresie);
            
            free(expresie);
            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 2:
            system("clear");
            printf("- Arbori de Expresie -\n\n");

            printf("(expresie): ");
            fgets(expresie, MAXL, stdin);
            while(expresie[index] != '\n')  ++index;
            expresie[index] = '\0';

            ControlOE(2, expresie);

            free(expresie);
            ReturnToPrev();
            return MeniuOperatiiExtinse();
            break;
        case 3:
            free(expresie);
            meniu();
            break;
        case 4:
            free(expresie);
            exit(0);
            break;
        default:
            free(expresie);
            printf("\nSomething went Wrong with MeniuOperatiiExtinse!\n");
            break;
    }
}


void meniu()
{
    system("clear");
    for(int i=0; i<MAXP; ++i)
        printf("%s\n", meniuPrincipal[i]);

    switch (AlegeOptiune())
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
            printf("\nSomething went Wrong with meniu!\n");
            break;
    }
}