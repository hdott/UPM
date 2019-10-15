#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stiva.h"
#include "coada.h"


typedef struct bst{
    int nr;
    char *str;
    struct bst *left,
                *right;
} BST;


static BST *head_bst = NULL; 

BST *GetHead(){
    return head_bst;
}

void SetHead(BST *head){
    head_bst = head;
}


BST *NewElement(const int nr, const char *str){
    BST *newp = (BST*) malloc(sizeof(BST));

    newp->nr = nr;
    newp->str = (char*) malloc(strlen(str)+1);
    strcpy(newp->str, str);
    newp->left = NULL;
    newp->right = NULL;

    return newp;
}

void Insert(BST **tracer, BST *newp){
    if(!(*tracer)){
        *tracer = newp;
    } else{
        if(newp->nr < (*tracer)->nr){
            Insert(&(*tracer)->left, newp);
        } else{
            Insert(&(*tracer)->right, newp);
        }
    }
}

int SearchKey(BST *tracer, int key){
    if(!tracer){
        return 0;
    } else{
        if(tracer->nr == key){
            return 1;
        } else if(key < tracer->nr){
            SearchKey(tracer->left, key);
        } else{
            SearchKey(tracer->right, key);
        }
    }
}

int SearchNonKey(BST *tracer, char *str){
    if(tracer){
        if(!strcmp(tracer->str, str)){
            return 1;
        } else{
            if(SearchNonKey(tracer->left, str)){
                return 1;
            }
            if(SearchNonKey(tracer->right, str)){
                return 1;
            }
        }
    }

    return 0;
}

static BST *FindSmallest(BST *tracer){
    while(tracer->left){
        tracer = tracer->left;
    }

    return tracer;
}

BST *DeleteKey(BST *tracer, KEY *key){
    if(!tracer){
        return tracer;
    }

    switch(key->opt){
        case 1:
            if(key->nr < tracer->nr){
                tracer->left = DeleteKey(tracer->left, key);
            } else if(key->nr > tracer->nr){
                tracer->right = DeleteKey(tracer->right, key);
            } else{
                if(!tracer->left){
                    BST *_tmp = tracer->right;

                    free(tracer->str);
                    free(tracer);
                    return _tmp;
                } else if(!tracer->right){
                    BST *_tmp = tracer->left;

                    free(tracer->str);
                    free(tracer);
                    return _tmp;
                }

                BST *_tmp = FindSmallest(tracer);
                tracer->nr = _tmp->nr;
                strcpy(tracer->str, _tmp->str);
                tracer->right = DeleteKey(tracer->right, key);
            }

            return tracer;
            break;
        case 0:
            if(strcmp(key->str, tracer->str)){
                tracer->left = DeleteKey(tracer->left, key);
                tracer->right = DeleteKey(tracer->right, key);
            } else{
                if(!tracer->left){
                    BST *_tmp = tracer->right;

                    free(tracer->str);
                    free(tracer);
                    return _tmp;
                } else if(!tracer->right){
                    BST *_tmp = tracer->left;

                    free(tracer->str);
                    free(tracer);
                    return _tmp;
                }

                BST *_tmp = FindSmallest(tracer);
                tracer->nr = _tmp->nr;
                strcpy(tracer->str, _tmp->str);
                tracer->right = DeleteKey(tracer->right, key);
            }

            return tracer;
            break;
        default:
            printf("Something went wrong with delete key!\n");
            break;
    }
}

void InOrder(BST *tracer){
    if(tracer){
        InOrder(tracer->left);
        printf("%d, %s\n", tracer->nr, tracer->str);
        InOrder(tracer->right);
    }
}

void PreOrder(BST *tracer){
    if(tracer){
        printf("%d, %s\n", tracer->nr, tracer->str);
        PreOrder(tracer->left);
        PreOrder(tracer->right);
    }
}

void PostOrder(BST *tracer){
    if(tracer){
        PostOrder(tracer->left);
        PostOrder(tracer->right);
        printf("%d, %s\n", tracer->nr, tracer->str);
    }
}

void InOrderWithStack(BST *tracer){
    while(tracer || !StackIsEmpty()){
        while(tracer){
            Push(NewNodeStack(tracer));
            tracer = tracer->left;
        }

        BST *_tmp = Pop();
        printf("%d, %s\n", _tmp->nr, _tmp->str);
        tracer = _tmp->right;
    }
}

void LevelOrderTraversalWithQueue(BST *tracer){
    Enqueue(NewNodeQueue(tracer));

    while(!QueueIsEmpty()){
        tracer = Dequeue();
        printf("%d, %s\n", tracer->nr, tracer->str);

        if(tracer->left){
            Enqueue(NewNodeQueue(tracer->left));
        }
        if(tracer->right){
            Enqueue(NewNodeQueue(tracer->right));
        }
    }
}

void DeleteTree(BST *tracer){
    if(tracer){
        DeleteTree(tracer->left);
        DeleteTree(tracer->right);

        free(tracer->str);
        free(tracer);
    }
}