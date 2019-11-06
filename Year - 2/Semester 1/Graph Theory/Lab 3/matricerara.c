#include <stdio.h>
#include <stdlib.h>



typedef struct NodeM{
    int value,
        i,
        j;
    struct NodeM *next;
} NodeM;

typedef struct MatriceRara{
    int i,
        j;
    NodeM *head;
    NodeM *tail;
} MatriceRara;


MatriceRara* initMatriceRara(int i, int j){
    MatriceRara *mr = (MatriceRara*) malloc(sizeof(MatriceRara));
    mr->i = i;
    mr->j = j;
    mr->head = NULL;
    mr->tail = NULL;

    return mr;
}

NodeM* newNodeM(int i, int j, int value){
    NodeM *node = (NodeM*) malloc(sizeof(NodeM));
    node->i = i;
    node->j = j;
    node->next = NULL;

    return node;
}

void adaugaValoare(MatriceRara *mr, NodeM *node){
    if(!mr->head){
        mr->head = node;
        mr->tail = node;
    } else{
        mr->tail = mr->tail->next = node;
    }
}

void deleteMatriceRara(MatriceRara *mr){
    NodeM *tracer = mr->head;

    while(tracer){
        NodeM *_toDelete = tracer;
        tracer = tracer->next;
        free(_toDelete);
    }
    free(mr);
}

void printMatriceRara(MatriceRara *mr){
    NodeM *tracer = mr->head;
    while(tracer){
        printf("")
    }
}