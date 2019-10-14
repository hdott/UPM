typedef struct bst BST;

extern BST *head_bst;

BST *NewElement(const int nr, const char *str);
void Insert(BST *tracer, BST *newp);
