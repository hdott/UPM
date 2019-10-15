#include "menu.h"

typedef struct bst BST;


BST *GetHead();
void SetHead(BST *head);
BST *NewElement(const int nr, const char *str);
void Insert(BST **tracer, BST *newp);
int SearchKey(BST *tracer, int key);
int SearchNonKey(BST *tracer, char *str);
BST *DeleteKey(BST *tracer, KEY *key);
void InOrder(BST *tracer);
void PreOrder(BST *tracer);
void PostOrder(BST *tracer);
void InOrderWithStack(BST *tracer);
void LevelOrderTraversalWithQueue(BST *tracer);
void DeleteTree(BST *tracer);
