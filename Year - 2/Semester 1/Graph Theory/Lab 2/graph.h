
typedef struct Edge Edge;
typedef struct Graph Graph;
// typedef struct AdjListNode AdjListNode;
typedef struct AdjList AdjList;
typedef struct AdjMatrix AdjMatrix;


Graph* initGraph(int V, int E);
void addEdge(Graph *g, int x, int y);
int removeEdge(Graph *g, int x, int y);
void deleteGraph(Graph *g);

AdjList* initAdjList(const Graph *g);
AdjList* createAdjList(const Graph *g);
void deleteAdjList(AdjList *adj);
void printAdjList(const AdjList *adj);

AdjMatrix* createAdjMatrix(const Graph *g);
AdjMatrix* createAdjMatrixFromArr(int V, const int **arr);
void deleteAdjMatrix(AdjMatrix *matrix);
void printAdjMatrix(const AdjMatrix *matrix);
Graph* createGraphFromAdjMatrix(const AdjMatrix *matrix);