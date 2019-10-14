#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct bst{
    int nr;
    char *str;
    struct bst *left,
                *right;
} BST;


static BST *head_bst = NULL;


BST *NewElement(const int nr, const char *str){
    BST *newp = (BST*) malloc(sizeof(BST));

    newp->nr = nr;
    newp->str = (char*) malloc(strlen(str));
    strcpy(newp->str, str);
    newp->left = NULL;
    newp->right = NULL;

    return newp;
}

void Insert(BST *tracer, BST *newp){
    if(!tracer){
        tracer = newp;
    } else{
        if(newp->nr < tracer->nr){
            Insert(tracer->left, newp);
        } else{
            Insert(tracer->right, newp);
        }
    }
}