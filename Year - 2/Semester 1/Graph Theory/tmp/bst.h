typedef struct bst BST;


BST *GetHead();
void SetHead(BST *head);
BST *NewElement(const int nr, const char *str);
void Insert(BST **tracer, BST *newp);
int SearchKey(BST *tracer, int key);
int SearchNonKey(BST *tracer, char *str);
int InOrder(BST *tracer);
void PreOrder(BST *tracer);
void PostOrder(BST *tracer);
void DeleteTree(BST *tracer);
