#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define MAXL 100;


void menu(){
    system("clear");

    printf("1. Inserarea unui nod\n");
    printf("2. Cautarea\n");
    printf("3. Stergerea unui nod\n");
    printf("4. Parcurgerea Arborelui\n");
    printf("5. Exit\n\n");

    int opt;
    printf("Selecteaza: ");
    scanf("%d", &opt);
    getchar();

    switch(opt){
        case 1:
            Insert(head_bst, NewElement(nr, str));
            break;
        default:
            break;
    }
}

void opt_1_InsertNode(){
    printf("~ Inserarea unui nod ~\n\n");

    
    // if()
}