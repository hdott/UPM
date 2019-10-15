#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
// #include "menu.h"
// #define MAXL 100


static void opt_1_InsertNode();
static void menuCautarea();
static void CautaCheie();
static void CautaNonCheie();
static void menuParcurgereaArb();
static void StergereNod();


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
        case 3:
            do{
                StergereNod();
            } while(ReturnOrContinue() != 'b');

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
        printf("\nNumarul [%d] a fost gasit cu Succes!\n", nr);
    } else{
        printf("\nNumarul [%d] NU a fost gasit!\n", nr);
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
        printf("\nCuvantul [%s] a fost gasit cu Succes!\n", str);
    } else{
        printf("\nCuantul [%s] NU a fost gasit!\n", str);
    }
}

static void StergereNod(){
    system("clear");

    printf("~ Stergerea unui nod ~\n\n");

    KEY key;
    printf("Introduceti un numar si o cheie:\n");
    printf("\t- numar(1 pentru cheie int)\n");
    printf("\t- numar(0 pentru cheie cuvant)\n");
    scanf("%d", &key.opt);
    if(key.opt == 1){
        scanf("%d", &key.nr);
    } else if(!key.opt){
        scanf("%s", key.str);
    } else{
        printf("\n[ERR] Optiunea nu este disponibila!\n");
    }
    getchar();

    BST *_tmp = GetHead();
    switch(key.opt){
        case 1:
            if(SearchKey(GetHead(), key.nr)){
                _tmp = DeleteKey(_tmp, &key);
                SetHead(_tmp);

                printf("\nNodul cu cheia [%d] a fost sters cu Succes!\n\n", key.nr);
            } else{
                printf("\nNodul cu cheia [%d] NU Exista!\n", key.nr);
            }
            break;
        case 0:
            if(SearchNonKey(GetHead(), key.str)){
                _tmp = DeleteKey(_tmp, &key);
                SetHead(_tmp);

                printf("\nNodul cu nonCheia [%s] a fost sters cu Succes!\n\n", key.str);
            } else{
                printf("\nNodul cu nonCheia [%s] Nu Exista!\n\n", key.str);
            }
            break;
        default:
            printf("\nSomething went wrong with StergereNod!\n");
            break;
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
        case 4:
            system("clear");

            printf("~ Folosind o Stiva ~\n\n");
            InOrderWithStack(GetHead());

            Return();
            return menuParcurgereaArb();
            break;
        case 5:
            system("clear");

            printf("~ Folosind o Coada ~\n\n");
            LevelOrderTraversalWithQueue(GetHead());

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