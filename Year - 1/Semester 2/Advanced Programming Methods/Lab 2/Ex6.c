/* Fie o matrice rara, adica o matrice, avand majoritatea elementelor nule.
 * Elementele acestor matrici se memoreaza sub forma unui triplet (i, j, val);
 * Se defineste o structura astfel:
 * struct elem{
 * int x, y, val;
 * };
 * Apoi o structura care reprezinta matricea:
 * struct mRara{
 * int nrlinii, nrcol, nrDeElementeNeNule;
 * element v[100];
 * };
 * Sa se implementeze functii pentru urmatoarele:
 *  - Citirea unei matrici rare;
 *  - Afisarea sub forma matriceala (cu linii si coloane);
 *  - Adunarea a doua matrici rare;
 *  - Inmultirea a doua matrici rare;
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct element
{
    int x;
    int y;
    int val;
} element;

typedef struct mRara
{
    int nrLinii;
    int nrColoane;
    int nrDeElementeNeNule;
    element v[MAX];
} mRara;

mRara matriceP;
mRara matriceS;
mRara matriceADD;
mRara matriceMULT;

void ReadMRara(mRara matrice)
{
    printf("Introduceti marimea unei matrici:\n");
        printf("(linii coloane): ");
        scanf("%d %d", &matrice.nrLinii, &matrice.nrColoane);

    printf("Introduceti numarul de elemente nenule ale matricei:\n");
        printf("(nr): ");
        scanf("%d", &matrice.nrDeElementeNeNule);
    
    printf("Introduceti elementele nenule ale matricei:\n");
    for(int i=0; i<matrice.nrDeElementeNeNule; ++i)
    {
        printf("(x y val): ");
        scanf("%d %d %d", &matrice.v[i].x, &matrice.v[i].y, &matrice.v[i].val);
    }

    matrice.v[matrice.nrDeElementeNeNule].val = 0;
}

void PrintMRara(mRara matrice, char *string)
{
    printf("\nMatricea %s este:\n", string);

    for(int i=0, x=0; i<matrice.nrLinii; ++i)
    {
        for(int j=0; j<matrice.nrColoane; ++j)
        {
            if(i != matrice.v[x].x || j != matrice.v[x].y)
                printf("%3d", 0);
            else    printf("%3d", matrice.v[x++].val);
        }
        puts("");
    }
}

void AddTwoMRara(mRara matrice1, mRara matrice2)
{
    matriceADD = matrice1;

    for(int i=0; !matrice1.v[i].val; ++i)
        for(int j=0; !matrice2.v[j].val; ++j)
        {
            if(matrice2.v[j].x != matrice1.v[i].x)
            {
                if(matrice2.v[j].x > matrice1.v[i].x)   break;

                if(matrice2.v[j].x == matrice1.v[i].x && 
                    matrice2.v[j].y > matrice1.v[i].y)  break;

                continue;
            }

            if(matrice2.v[j].y == matrice1.v[i].y)
            {
                matriceADD.v[i].val += matrice2.v[j].val;
            }
        }
}

void MultiplyTwoMRara(mRara matrice1, mRara matrice2)
{
    matriceMULT.nrLinii = matrice1.nrLinii;
    matriceMULT.nrColoane = matrice2.nrColoane;
    matriceMULT.nrDeElementeNeNule = 0;

    int *tempVector1 = (int*) calloc(matriceMULT.nrLinii, sizeof(int)); 
    int *tempVector2 = (int*) calloc(matriceMULT.nrLinii, sizeof(int)); 

    for(int i=0; i<matriceMULT.nrLinii; ++i)
        for(int j=0; j<matriceMULT.nrColoane; ++j)
        {
            int tempValue = 0;
            
            for(int x=0; !matrice1.v[x].val; ++x)
            {
                if(matrice1.v[x].x > i) break;

                if(matrice1.v[x].x == i)    
                    tempVector1[matrice1.v[x].y] = matrice1.v[x].val;                
            }

            for(int y=0; !matrice2.v[y].val; ++y)
            {
                if(matrice2.v[y].y == j)    
                    tempVector2[matrice2.v[y].x] = matrice2.v[y].val; 
            }

            for(int z=0; z<matriceMULT.nrLinii; ++z)
                if(!(tempValue += tempVector1[z]*tempVector2[z]))   break;

            if(!tempValue)  continue;
            else
            {
                matriceMULT.v[matriceMULT.nrDeElementeNeNule].x = i;
                matriceMULT.v[matriceMULT.nrDeElementeNeNule].y = j;
                matriceMULT.v[matriceMULT.nrDeElementeNeNule].val = tempValue;
                matriceMULT.nrDeElementeNeNule++;
            }
        }

    free(tempVector1);
    free(tempVector2);
}


int main(void)
{
    ReadMRara(matriceP);
    ReadMRara(matriceS);

    AddTwoMRara(matriceP, matriceS);
    MultiplyTwoMRara(matriceP, matriceS);

    return 0;
}