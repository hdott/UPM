/*
Să se scrie un program care afişează ca întreg în baza 10 conţinutul primului octet al unei variabile de tip float. 
Să se scrie un program care afişează ca întreg în baza 10 conţinutul ultimului octet al unei variabile de tip float. 
Să se scrie un program care afişează ca întreg în baza 2 unei variable de tip float.
*/

#include <stdio.h>
#include <stdlib.h>
#define OCTET 8

void print_vector_reverse(int V[], int elem, char s[])
{
    printf("%s este: ", s);
    for(int i = elem-1; i>=0; --i)
        printf("%d", V[i]);
    printf("\n");
}

void main()
{
    float x = 1234.1234;

    __int8_t *bytes = (__int8_t*)&x;                        //aloca pointerul *bytes adresa primului octet al lui x
        printf("Valoarea fiecarui octet al %f este:\n",x);
        for(int i=0; i<sizeof(x); ++i)                      //printeaza valoarea fiecarui octet al lui x
            printf("byte[%d] = %d\n",i+1,*(bytes+i));
    
    int *baza = (int*)&x;                                   //aloca pointerului *baza adresa primilor 4octeti al lui x
        printf("\nFLOAT TO INT este: %d\n",*baza);          //practic valoarea binara stocata la adresa lui x se duce ca intreg la baza
    int y = *baza;                                          //y ia valoarea din baza pentru a putea modifica y mai departe
    int *V = (int*) malloc(OCTET*sizeof(x));
        for(int i=0; i<OCTET*sizeof(x); ++i,y/=2)
            V[i] = y%2;

    print_vector_reverse(V,OCTET*sizeof(x),"FLOAT TO BIN");
    
    free(V);
}
