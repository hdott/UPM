#pragma once


typedef struct NodeM *NodeM;
typedef struct MatriceRara *MatriceRara;


MatriceRara* initMatriceRara(int i, int j);
NodeM* newNodeM(int i, int j, int value);
void adaugaValoare(MatriceRara *mr, NodeM *node);
void deleteMatriceRara(MatriceRara *mr);
MatriceRara* addMR(const MatriceRara* mr1, const MatriceRara* mr2);
void printMatriceRaraH(MatriceRara *mr);
void printMatriceRaraV(MatriceRara *mr);
void printAddMR(const MatriceRara *mr1, const MatriceRara *mr2, const MatriceRara *mr3);
void printMRMatrix(const MatriceRara *mr, char ch);
void sortMR(MatriceRara *mr);