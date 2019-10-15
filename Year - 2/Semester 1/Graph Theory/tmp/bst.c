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

BST *GetHead(){
    return head_bst;
}

void SetHead(BST *head){
    head_bst = head;
}


BST *NewElement(const int nr, const char *str){
    BST *newp = (BST*) malloc(sizeof(BST));

    newp->nr = nr;
    newp->str = (char*) malloc(strlen(str));
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
    if(!tracer){
        return 0;
    } else{
        if(!strcmp(tracer->str, str)){
            return 1;
        } else{
            SearchNonKey(tracer->left, str);
            SearchNonKey(tracer->right, str);
        }
    }
}

//stergerea unui nod

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

void DeleteTree(BST *tracer){
    if(tracer){
        DeleteTree(tracer->left);
        DeleteTree(tracer->right);

        free(tracer);
    }
}