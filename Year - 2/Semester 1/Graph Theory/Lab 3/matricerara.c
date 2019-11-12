#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    node->value = value;
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

static MatriceRara* copyMR(const MatriceRara *mr){
    MatriceRara *mr1 = initMatriceRara(mr->i, mr->j);

    NodeM *tracer = mr->head;
    while(tracer){
        adaugaValoare(mr1, newNodeM(tracer->i, tracer->j, tracer->value));

        tracer = tracer->next;
    }

    return mr1;
}
void printMatriceRaraH(MatriceRara *mr){
    NodeM *tracer = mr->head;
    printf("V | ");
    while(tracer){
        printf("%2d ", tracer->value);
        tracer = tracer->next;
    }
    putchar('\n');

    tracer = mr->head;
    printf("I | ");
    while(tracer){
        printf("%2d ", tracer->i);
        tracer = tracer->next;
    }
    putchar('\n');

    tracer = mr->head;
    printf("J | ");
    while(tracer){
        printf("%2d ", tracer->j);
        tracer = tracer->next;
    }
    putchar('\n');
}

void printMatriceRaraV(MatriceRara *mr){
    NodeM *tracer = mr->head;
    printf("%4c %3c %3c\n", 'V', 'I', 'J');
    for(int i = 0; i < 13; ++i){
        putchar('-');
    }
    putchar('\n');
    while(tracer){
        printf("(%3d,%3d,%3d)\n", tracer->i, tracer->j, tracer->value);
        tracer = tracer->next;
    }
}

// static MatriceRara* reunionMR(const MatriceRara *mr1, const MatriceRara *mr2){
//     MatriceRara *mr3 = initMatriceRara(mr1->i, mr1->j);

//     NodeM *tracer1, *tracer2;
//     tracer1 = mr1->head;
//     tracer2 = mr2->head;
//     while(tracer1 || tracer2){
//         if(!tracer1){
//             adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
//         }
//         if(!tracer2){
//             adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
//         }

//         if(tracer1->i < tracer2->i){
//             adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
//             tracer1 = tracer1->next;
//             continue;
//         }

//         if(tracer1->i > tracer2->i){
//             adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
//             tracer2 = tracer2->next;
//             continue;
//         }

//         if(tracer1->i == tracer2->i){
//             if(tracer1->j < tracer2->j){
//                 adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
//                 tracer1 = tracer1->next;
//                 continue;
//             }

//             if(tracer1->j > tracer2->j){
//                 adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
//                 tracer2 = tracer2->next;
//                 continue;
//             }

//             if(tracer1->j == tracer2->j){
//                 if(tracer1->value + tracer2->value){
//                     adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j,
//                                                 tracer1->value + tracer2->value));
//                 }
//                 tracer1 = tracer1->next;
//                 tracer2 = tracer2->next;
//             }
//         }
//     }

//     return mr3;
// }

MatriceRara* addMR(const MatriceRara* mr1, const MatriceRara* mr2){
    MatriceRara *mr3 = initMatriceRara(mr1->i, mr1->j);

    NodeM *tracer1, *tracer2;
    tracer1 = mr1->head;
    tracer2 = mr2->head;
    while(tracer1 || tracer2){
        if(!tracer1){
            adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
            tracer2 = tracer2->next;
            continue;
        }
        if(!tracer2){
            adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
            tracer1 = tracer1->next;
            continue;
        }

        if(tracer1->i < tracer2->i){
            adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
            tracer1 = tracer1->next;
            continue;
        }

        if(tracer1->i > tracer2->i){
            adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
            tracer2 = tracer2->next;
            continue;
        }

        if(tracer1->i == tracer2->i){
            if(tracer1->j < tracer2->j){
                adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j, tracer1->value));
                tracer1 = tracer1->next;
                continue;
            }

            if(tracer1->j > tracer2->j){
                adaugaValoare(mr3, newNodeM(tracer2->i, tracer2->j, tracer2->value));
                tracer2 = tracer2->next;
                continue;
            }

            if(tracer1->j == tracer2->j){
                if(tracer1->value + tracer2->value){
                    adaugaValoare(mr3, newNodeM(tracer1->i, tracer1->j,
                                                tracer1->value + tracer2->value));
                }
                tracer1 = tracer1->next;
                tracer2 = tracer2->next;
            }
        }
    }

    return mr3;
}

void printMRMatrix(const MatriceRara *mr, char ch){
    for(int j = 0; j <= mr->j; ++j){
        if(!j){
            printf("[%c]", ch);
        } else{
            printf("%3d", j);
        }
    }
    putchar('\n');
    for(int j = 0; j <= (mr->j+1)*3; ++j){
        putchar('-');
    }
    putchar('\n');

    NodeM *tr = mr->head;
    char str[10];
    for(int i = 1; i <= mr->i; ++i){
        sprintf(str, "%d", i);
        printf("%d", i);
        printf("%*c", 3-(int)strlen(str), '|');
        for(int j = 1; j <= mr->j; ++j){
            if(tr){
                if(tr->i == i){
                    if(tr->j != j){
                        printf("%3d", 0);
                    } else{
                        printf("%3d", tr->value);
                        tr = tr->next;
                    }
                } else{
                    printf("%3d", 0);
                }
            } else{
                printf("%3d", 0);
            }
        }
        putchar('\n');
    }
}

void printAddMR(const MatriceRara *mr1, const MatriceRara *mr2, const MatriceRara *mr3){
    int I = mr1->i,
        J = mr1->j;
        
    NodeM *tr1 = mr1->head,
            *tr2 = mr2->head,
            *tr3 = mr3->head;
    char ch = 'A';
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j <= J; ++j){
            if(!j){
                printf("[%c]", ch);
            } else{
                printf("%3d", j);
            }
        }
        ch++;
        putchar('\t');
    }
    putchar('\n');
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j <= (J+1)*3; ++j){
            putchar('-');
        }
        putchar('\t');
    }
    putchar('\n');
    char str[10];
    for(int i = 1; i <= I; ++i){
        sprintf(str, "%d", i);
        printf("%d", i);
        printf("%*c", 3-(int)strlen(str), '|');
        for(int j = 1; j <= J; ++j){
            if(tr1){
                if(tr1->i == i){
                    if(tr1->j != j){
                        printf("%3d", 0);
                    } else{
                        printf("%3d", tr1->value);
                        tr1 = tr1->next;
                    }
                } else{
                    printf("%3d", 0);
                }
            } else{
                printf("%3d", 0);
            }
        }
        putchar('\t');
        printf("%d", i);
        printf("%*c", 3-(int)strlen(str), '|');
        for(int j = 1; j <= J; ++j){
            if(tr2){
                if(tr2->i == i){
                    if(tr2->j != j){
                        printf("%3d", 0);
                    } else{
                        printf("%3d", tr2->value);
                        tr2 = tr2->next;
                    }
                } else{
                    printf("%3d", 0);
                }
            } else{
                printf("%3d", 0);
            }
        }
        putchar('\t');
        printf("%d", i);
        printf("%*c", 3-(int)strlen(str), '|');
        for(int j = 1; j <= J; ++j){
            if(tr3){
                if(tr3->i == i){
                    if(tr3->j != j){
                        printf("%3d", 0);
                    } else{
                        printf("%3d", tr3->value);
                        tr3 = tr3->next;
                    }
                } else{
                    printf("%3d", 0);
                }
            } else{
                printf("%3d", 0);
            }
        }
        putchar('\n');
    }
}

void sortMR(MatriceRara *mr){
    NodeM *tr1 = mr->head,
            *tr2;
    
    int count = 0;
    while(tr1){
        count++;
        tr1 = tr1->next;
    }

    NodeM *_tmp = (NodeM*) malloc(count * sizeof(NodeM));
    tr1 = mr->head;
    for(int i = 0; i < count; ++i){
        _tmp[i].i = tr1->i;
        _tmp[i].j = tr1->j;
        _tmp[i].value = tr1->value;
        tr1 = tr1->next;
    }

    NodeM _mp;
    for(int i = 0; i < count-1; ++i){
        for(int j = i+1; j < count; ++j){
            if(_tmp[j].i < _tmp[i].i){
                _mp.i = _tmp[i].i;
                _mp.j = _tmp[i].j;
                _mp.value = _tmp[i].value;
                _tmp[i].i = _tmp[j].i;
                _tmp[i].j = _tmp[j].j;
                _tmp[i].value = _tmp[j].value;
                _tmp[j].i = _mp.i;
                _tmp[j].j = _mp.j;
                _tmp[j].value =  _mp.value;
            }
            if(_tmp[j].i == _tmp[i].i){
                if(_tmp[j].j < _tmp[i].j){
                    _mp.i = _tmp[i].i;
                    _mp.j = _tmp[i].j;
                    _mp.value = _tmp[i].value;
                    _tmp[i].i = _tmp[j].i;
                    _tmp[i].j = _tmp[j].j;
                    _tmp[i].value = _tmp[j].value;
                    _tmp[j].i = _mp.i;
                    _tmp[j].j = _mp.j;
                    _tmp[j].value =  _mp.value;
                }
            }
        }
    }

    tr1 = mr->head;
    for(int i = 0; i < count; ++i){
        tr1->i = _tmp[i].i;
        tr1->j = _tmp[i].j;
        tr1->value = _tmp[i].value;
        tr1 = tr1->next;
    }

    free(_tmp);
}