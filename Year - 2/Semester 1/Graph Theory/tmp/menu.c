#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "menu.h"
#define MAXL 100


static void opt_1_InsertNode();
static void menuCautarea();
static void CautaCheie();
static void CautaNonCheie();
static void menuParcurgereaArb();


static void Return(){
    printf("\tPress Enter to Return...");
    getchar();
}

static char ReturnOrContinue()
{
    char roc;
    printf("\n\tPress 'b' to Return... ");
    scanf("%c", &roc);

    if(roc != '\n'){
        getchar();
    }

    return roc;
}

static int SelecteazaOptiune(){
    int opt;
    printf("Selecteaza: ");
    scanf("%d", &opt);
    getchar();

    return opt;
}

void menu(){
    system("clear");

    printf("1. Inserarea unui nod\n");
    printf("2. Cautarea\n");
    printf("3. Stergerea unui nod\n");
    printf("4. Parcurgerea Arborelui\n");
    printf("5. Exit\n\n");

    
    switch(SelecteazaOptiune()){
        case 1:
            do{
                opt_1_InsertNode();
            } while(ReturnOrContinue() != 'b');
            
            return menu();
            break;
        case 2:
            menuCautarea();

            return menu();
            break;
        case 4:
            menuParcurgereaArb();

            return menu();
            break;
        case 5:
            DeleteTree(GetHead());
            exit(0);
            break;
        default:
            printf("\n~*** Something went Wrong! ***~\n");
            break;
    }
}


static void opt_1_InsertNode(){
    system("clear");
    printf("~ Inserarea unui nod ~\n\n");

    int nr;
    char str[MAXL];
    printf("Introduceti un numar(intreg) si un cuvant: ");
    scanf("%d %s", &nr, str);
    getchar();
    
    BST *bst_head = GetHead();
    Insert(&bst_head, NewElement(nr, str));
    SetHead(bst_head);
    printf("\n%d, %s a fost adaugat cu succes!\n", nr, str);
}


static void menuCautarea(){
    system("clear");
    
    printf("~ Cautarea: ~\n\n");
    printf("1. In functie de o informatie care este cheie\n");
    printf("2. In functie de o informatie care nu este cheie\n");
    printf("3. Return\n\n");


    switch(SelecteazaOptiune()){
        case 1:
            do{
               CautaCheie(); 
            } while(ReturnOrContinue() != 'b');

            return menuCautarea();
            break;
        case 2:
            do{
                CautaNonCheie();
            } while(ReturnOrContinue() != 'b');
            
            return menuCautarea();
            break;
        case 3:
            return menu();
            break;
        default:
            printf("Something went wrong in [menuCautarea]!\n");
            break;
    }
}

static void CautaCheie(){
    system("clear");

    printf("~ Cautarea in functie de o informatie care este cheie ~\n\n");
    
    int nr;
    printf("Introduceti numarul: ");
    scanf("%d", &nr);
    getchar();

    if(SearchKey(GetHead(), nr)){
        printf("\nNumarul [%d] a fost gasit cu Succes!\n");
    } else{
        printf("\nNumarul [%d] NU a fost gasit!\n");
    }
}

static void CautaNonCheie(){
    system("clear");

    printf("~ Cautarea in functie de o informatie care nu este cheie ~\n\n");

    char str[MAXL];
    printf("Introduceti cuvantul cautat: ");
    scanf("%s", str);
    getchar();

    if(SearchNonKey(GetHead(), str)){
        printf("\nCuvantul [%s] a fost gasit cu Succes!\n");
    } else{
        printf("\nCuantul [%s] NU a fost gasit!\n");
    }
}


static void menuParcurgereaArb(){
    system("clear");

    printf("~ Parcurgerea ~\n\n");
    printf("1. InOrdine\n");
    printf("2. PreOrdine\n");
    printf("3. PostOrdine\n");
    printf("4. Folosind o Stiva\n");
    printf("5. Folosind o Coada\n");
    printf("6. Return\n\n");


    switch(SelecteazaOptiune()){
        case 1:
            system("clear");

            printf("~ InOrdine ~\n\n");
            InOrder(GetHead());

            Return();
            return menuParcurgereaArb();
            break;
        case 2:
            system("clear");

            printf("~ PreOrdine ~\n\n");
            PreOrder(GetHead());

            Return();
            return menuParcurgereaArb();
            break;
        case 3:
            system("clear");

            printf("~ PostOrdine ~\n\n");
            PostOrder(GetHead());

            Return();
            return menuParcurgereaArb();
            break;
        case 6:
            return menu();
            break;
        default:
            printf("Something went wrong with [menuParcurgereArb]!\n");
            break;
    }
}