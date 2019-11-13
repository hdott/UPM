#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "matricerara.h"

void generateRandomMR(MatriceRara *mr1, MatriceRara *mr2, int opt, int I, int J);


int main(int argc, char **argv){
    int opt = 0;
    int arrCompute = 0,
        I,
        J;
    if(argc > 1 && argc == 2){
        if(!strcmp(argv[1], "-h")){
            opt = 'h';
        } else if(!strcmp(argv[1], "-v")){
            opt = 'v';
        } else if(!strcmp(argv[1], "-a")){
            opt = 'a';
        } else if(!strcmp(argv[1], "-1")){
            opt = 1;
        } else if(!strcmp(argv[1], "-2")){
            opt = 2;
        } else if(!strcmp(argv[1], "-3")){
            opt = 3;
        }
    } else if(argc > 1 && argc == 4){
        if(!strcmp(argv[1], "-h")){
            opt = 'h';
        } else if(!strcmp(argv[1], "-v")){
            opt = 'v';
        } else if(!strcmp(argv[1], "-a")){
            opt = 'a';
        } else if(!strcmp(argv[1], "-1")){
            opt = 1;
        } else if(!strcmp(argv[1], "-2")){
            opt = 2;
        } else if(!strcmp(argv[1], "-3")){
            opt = 3;
        }
        
        if(!strcmp(argv[2], "-c1")){
            char *pE;
            I = strtol(argv[3], &pE, 10);
            J = strtol(pE+1, &pE, 10);
            arrCompute = 1;
        } else if(argv[2], "-c2"){
            char *pE;
            I = strtol(argv[3], &pE, 10);
            J = strtol(pE+1, &pE, 10);
            arrCompute = 2;
        }
    }

    MatriceRara *A,
                *B;

    switch(arrCompute){
        case 0:
            A = initMatriceRara(10, 8);
            adaugaValoare(A, newNodeM(1, 2, 1));
            adaugaValoare(A, newNodeM(1, 7, 4));
            adaugaValoare(A, newNodeM(2, 4, 4));
            adaugaValoare(A, newNodeM(2, 8, 7));
            adaugaValoare(A, newNodeM(3, 5, -1));
            adaugaValoare(A, newNodeM(4, 1, 9));
            adaugaValoare(A, newNodeM(4, 5, 10));   // diff
            adaugaValoare(A, newNodeM(5, 1, 3));
            adaugaValoare(A, newNodeM(5, 2, 2));
            adaugaValoare(A, newNodeM(5, 8, 5));
            adaugaValoare(A, newNodeM(7, 2, 8));
            adaugaValoare(A, newNodeM(7, 4, 6));
            adaugaValoare(A, newNodeM(7, 5, 7));
            adaugaValoare(A, newNodeM(9, 6, 12));
            adaugaValoare(A, newNodeM(10, 2, 31));
            adaugaValoare(A, newNodeM(10, 8, 87));

            B = initMatriceRara(10, 8);
            adaugaValoare(B, newNodeM(1, 2, 1));
            adaugaValoare(B, newNodeM(1, 7, 4));
            adaugaValoare(B, newNodeM(2, 4, 4));
            adaugaValoare(B, newNodeM(2, 8, 7));
            adaugaValoare(B, newNodeM(3, 5, -1));
            adaugaValoare(B, newNodeM(4, 1, 9));
            adaugaValoare(B, newNodeM(4, 2, 10));   // diff
            adaugaValoare(B, newNodeM(5, 1, -3));
            adaugaValoare(B, newNodeM(5, 2, 2));
            adaugaValoare(B, newNodeM(5, 8, 5));
            adaugaValoare(B, newNodeM(7, 2, 8));
            adaugaValoare(B, newNodeM(7, 4, 6));
            adaugaValoare(B, newNodeM(7, 5, 7));
            adaugaValoare(B, newNodeM(9, 6, -12));
            adaugaValoare(B, newNodeM(10, 2, 31));
            adaugaValoare(B, newNodeM(10, 8, -87));
            break;
        case 1:
            A = initMatriceRara(I, J);
            B = initMatriceRara(I, J);
            generateRandomMR(A, B, 0, I, J);
            break;
        case 2:
            A = initMatriceRara(I, J);
            B = initMatriceRara(I, J);
            generateRandomMR(A, B, 1, I, J);
            break;
    }
    

    

    MatriceRara *C = addMR(A, B);
    
    switch(opt){
        case 1:
            printMRMatrix(A, 'A');
            break;
        case 2:
            printMRMatrix(B, 'B');
            break;
        case 3:
            printMRMatrix(C, 'C');
            break;
        case 'h':
            // printMatriceRaraH(A);
            // printMatriceRaraH(B);
            printMatriceRaraH(C);
            break;
        case 'v':
            printMatriceRaraV(C);
            break;
        case 0:
        case 'a':
            // printMatriceRaraH(A);
            // printMatriceRaraH(B);
            // printMatriceRaraH(C);
            printAddMR(A, B, C);
            break;
    }

    deleteMatriceRara(A);
    deleteMatriceRara(B);
    deleteMatriceRara(C);

    return 0;
}


static int isPresent(int size, int ar[], int key){
    for(int i = 0; i < size; ++i){
        if(ar[i] == key){
            return 1;
        }
    }
    return 0;
}

void generateRandomMR(MatriceRara *mr1, MatriceRara *mr2, int opt, int I, int J){
    srand((unsigned) time(0));

    switch(opt){
        case 0:
            for(int i = 1; i <= I; ++i){
                int _non0 = random() % J + 1;
                if(_non0 > J/2){
                    _non0 = J - _non0;
                }
                int *ar = (int*) calloc(_non0, sizeof(int));
                int _tmp;
                for(int j = 1; j <= _non0; ++j){
                    while(isPresent(_non0, ar, _tmp = random() % J + 1))    ;

                    adaugaValoare(mr1, newNodeM(i, _tmp, random() % 48 + 1));
                    adaugaValoare(mr2, newNodeM(i, _tmp, random() % 48 + 1));
                    ar[j-1] = _tmp;
                }
                free(ar);
            }

            sortMR(mr1);
            sortMR(mr2);
            break;
        case 1:
            for(int i = 1; i <= I; ++i){
                int _non0 = random() % J + 1;
                if(_non0 > J/2){
                    _non0 = J - _non0;
                }
                int *ar = (int*) calloc(_non0, sizeof(int));
                int _tmp;
                for(int j = 1; j <= _non0; ++j){
                    while(isPresent(_non0, ar, _tmp = random() % J + 1))    ;

                    adaugaValoare(mr1, newNodeM(i, _tmp, random() % 48 + 1));
                    ar[j-1] = _tmp;
                }
                free(ar);
            }
            for(int i = 1; i <= I; ++i){
                int _non0 = random() % J + 1;
                if(_non0 > J/2){
                    _non0 = J - _non0;
                }
                int *ar = (int*) calloc(_non0, sizeof(int));
                int _tmp;
                for(int j = 1; j <= _non0; ++j){
                    while(isPresent(_non0, ar, _tmp = random() % J + 1))    ;

                    adaugaValoare(mr2, newNodeM(i, _tmp, random() % 48 + 1));
                    ar[j-1] = _tmp;
                }
                free(ar);
            }
            
            sortMR(mr1);
            sortMR(mr2);
            break;
    }
}