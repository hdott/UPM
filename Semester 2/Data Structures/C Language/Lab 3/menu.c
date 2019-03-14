#include <stdio.h>
#include <stdlib.h>
#include "persons.h"
#include "menu.h"
#define MAXL 50
#define MeniuPrincipal 6
#define MeniuAdaugare 5
#define MeniuStergere 4
#define MeniuCautare 4


static char option_select[] = {"Alegeti optiunea: "};
static char meniu_principal[][MAXL] = {"1.Adaugare","2.Stergere","3.Cautare","4.Afisare",
                            "5.Distrugere", "6.Operatii Extinse"};
static char meniu_adaugare[][MAXL] = {"1.La inceput","2.La sfarsit",
                            "3.Inaintea unui element identificat prin nume",
                            "4.Dupa un element identificat prin nume","5.Return"};
static char meniu_stergere[][MAXL] = {"1.Primului","2.Ultimului",
                            "3.Unui element identificat prin nume si prenume","4.Return"};
static char meniu_cautare[][MAXL] = {"1.Dupa nume","2.Dupa prenume","3.Dupa varsta",
                                        "4.Return"};
static char nume[MAXL], prenume[MAXL], numeCheie[MAXL], prenumeCheie[MAXL];
static int varsta, varstaCheie;


static char Return_toPreviousMenu()
{
    getchar();
    printf("\n(ENTER pentru a continua, \"0\" pentru a reveni la meniul anterior) ");
    
    return getchar();
}

static void menuAdd()
{
    getchar();
    system("clear");
    char ch;
    
    for(int i=0; i<MeniuAdaugare; ++i)
        printf("%s\n", meniu_adaugare[i]);
    
    int optiune;
    printf("\n%s ", option_select);
        scanf("%d", &optiune);

    switch(optiune)
    {
        case  1:
            do
            {
                system("clear");
                printf("Adaugare - La Inceput -\n");
                printf("(nume prenume varsta): ");

                fscanf(stdin, "%s %s %d", nume, prenume, &varsta);
                    MainPersons(&personStart, NULL, NULL, -1, 1, 1,
                                NewPerson(nume, prenume, varsta));

                ch = Return_toPreviousMenu();
            } while (ch != '0');
            
            return menuAdd();
            break;
        case 2:
            do
            {
                system("clear");
                printf("Adaugare - La Sfarsit -\n");
                printf("(nume prenume varsta): ");

                fscanf(stdin, "%s %s %d", nume, prenume, &varsta);
                    MainPersons(&personStart, NULL, NULL, -1, 1, 2,
                                NewPerson(nume, prenume, varsta));

                ch = Return_toPreviousMenu();
            } while (ch != '0');

            return menuAdd();
            break;
        case 3:
            do
            {
                system("clear");
                printf("Adaugare - Inaintea unui element identificat prin nume -\n");
                printf("(nume prenume varsta identificator): ");

                fscanf(stdin, "%s %s %d %s", nume, prenume, &varsta, numeCheie);
                    MainPersons(&personStart, numeCheie, NULL, -1, 1, 3,
                                NewPerson(nume, prenume, varsta));

                ch = Return_toPreviousMenu();
            } while (ch != '0');
            
            return menuAdd();
            break;
        case 4:
            do
            {
                system("clear");
                printf("Adaugare - Dupa un element identificat prin nume -\n");
                printf("(nume prenume varsta identificator): ");

                fscanf(stdin, "%s %s %d %s", nume, prenume, &varsta, numeCheie);
                    MainPersons(&personStart, numeCheie, NULL, -1, 1, 4,
                                NewPerson(nume, prenume, varsta));
                            
                ch = Return_toPreviousMenu();
            } while (ch != '0');

            return menuAdd();
            break;
        case 5:
            menu(0);
            break;
        default:
            puts("ERROR in menuAdd Function!\n");
            break;
    }
}

static void menuDelete()
{
    getchar();
    system("clear");
    char ch;
    int count = 0;

    for(int i=0; i<MeniuStergere; ++i)
        printf("%s\n", meniu_stergere[i]);

    int optiune;
    printf("\n%s ", option_select);
        scanf("%d", &optiune);

    switch(optiune)
    {
        case 1:
            getchar();
            do
            {
                system("clear");
                printf("Stergere - Primul Element -\n");
                    MainPersons(&personStart, NULL, NULL, -1, 2, 1, NULL);
                
                (++count == 1) ?   puts("Primul element a fost sters.")    :
                                printf("Primele %d elemente au fost sterse.\n", count);

                printf("\n(ENTER pentru a continua, \"0\" pentru a reveni la meniul anterior) ");
                ch = getchar();
            } while (ch != '0');
            
            return menuDelete();
            break;
        case 2:
            getchar();
            do
            {
                system("clear");
                printf("Stergere - Ultimul Element -\n");
                    MainPersons(&personStart, NULL, NULL, -1, 2, 2, NULL);
                
                (++count == 1) ?   puts("A fost sters un element.")    :
                                printf("Au fost sterse %d elemente.\n", count);

                printf("\n(ENTER pentru a continua, \"0\" pentru a reveni la meniul anterior) ");
                ch = getchar();
            } while (ch != '0');
            
            return menuDelete();
            break;
        case 3:
            do
            {
                system("clear");
                printf("Stergere - Unui element identificat prin nume si prenume -\n");
                printf("(nume prenume): ");
                fscanf(stdin, "%s %s", numeCheie, prenumeCheie);
                    getchar();
                    MainPersons(&personStart, numeCheie, prenumeCheie, -1, 2, 3, NULL);
                
                (++count == 1) ?   puts("A fost sters un element.")    :
                                printf("Au fost sterse %d elemente.\n", count);

                printf("\n(ENTER pentru a continua, \"0\" pentru a reveni la meniul anterior) ");
                ch = getchar();
            } while (ch != '0');
            
            return menuDelete();
            break;
        case 4:
            menu(0);
            break;
        default:
            puts("ERROR in menuDelete Function!");
            break;
    }
}

static void menuLookFor()
{
    getchar();
    system("clear");
    char ch;

    for(int i=0; i<MeniuCautare; ++i)
        printf("%s\n", meniu_cautare[i]);

    int optiune;
    printf("\n%s ", option_select);
        scanf("%d", &optiune);

    switch(optiune)
    {
        case 1:
            do
            {
                system("clear");
                printf("Cautare - dupa nume -\n");
                printf("(nume): ");
                fscanf(stdin, "%s", numeCheie);
                    MainPersons(&personStart, numeCheie, NULL, -1, 3, 1, NULL);

                ch = Return_toPreviousMenu();
            } while (ch != '0');

            return menuLookFor();
            break;
        case 2:
            do
            {
                system("clear");
                printf("Cautare - dupa prenume -\n");
                printf("(prenume): ");
                fscanf(stdin, "%s", prenumeCheie);
                    MainPersons(&personStart, NULL, prenumeCheie, -1, 3, 2, NULL);

                ch = Return_toPreviousMenu();
            } while (ch != '0');

            return menuLookFor();
            break;
        case 3:
            do
            {
                system("clear");
                printf("Cautare - dupa varsta -\n");
                printf("(varsta): ");
                fscanf(stdin, "%d", &varstaCheie);
                    MainPersons(&personStart, NULL, NULL, varstaCheie, 3, 3, NULL);

                ch = Return_toPreviousMenu();
            } while (ch != '0');

            return menuLookFor();
            break;
        case  4:
            menu(0);
            break;
        default:
            puts("ERROR in menuLookFor Function!");
            break;
            
    }
}

void menu(int optiune)
{
    char ch;

    if(!optiune)
    {
        system("clear");

        for(int i=0; i<MeniuPrincipal-1; ++i)
            printf("%s\n", meniu_principal[i]);
        
        printf("\n%s: ", option_select);
            scanf("%d", &optiune);
    }
    
    if(optiune)
        switch(optiune)
        {
            case 1:
                menuAdd();
                break;
            case 2:
                menuDelete();
                break;
            case 3:
                menuLookFor();
                break;
            case 4:
                MainPersons(&personStart, NULL, NULL, -1, 4, -1, NULL);
                break;
            case 5:
                MainPersons(&personStart, NULL, NULL, -1, 5, -1, NULL);
            default:
                system("clear");
                getchar();
                puts("Optiunea selectata nu este disponibila!");
                printf("\nReveniti la meniul anterior?\n");
                    printf("(y/n): "), scanf("%c", &ch);
                
                (ch == 'y') ?   menu(0)  :
                                exit(1);
                break;
        }
}