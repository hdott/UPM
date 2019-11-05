#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Edge{
    int x,
        y;
} Edge;

typedef struct Graph{
    int V,
        E;
    Edge *edges;
} Graph;

typedef struct AdjListNode{
    int y;
    struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList{
    int V;
    struct AdjListNode **head;
} AdjList;

typedef struct AdjMatrix{
    int V;
    int **m;
} AdjMatrix;

static int it = 0;


Graph* initGraph(int V, int E){
    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->V = V;
    g->E = E;
    g->edges = (Edge*) malloc(E * sizeof(Edge));

    return g;
}

int addEdge(Graph *g, int x, int y){
    if(it >= g->E){
        return 0;
    }

    g->edges[it].x = x;
    g->edges[it].y = y;
    ++it;
    
    return 1;
}

int removeEdge(Graph *g, int x, int y){
    int as = 0;
    for(int i = 0; i < it; ++i){
        if(g->edges[i].x == x && g->edges[i].y == y && !as){
            as = 1;
        }
        if(as && i < it-1){
            g->edges[i].x = g->edges[i+1].x;
            g->edges[i].y = g->edges[i+1].y;
        }
    }

    if(as)  --it;
    return as;
}

void printGraph(Graph *g){
    for(int i = 0; i < g->E; ++i){
        printf("%d - %d\n", g->edges[i].x, g->edges[i].y);
    }
}

void deleteGraph(Graph *g){
    free(g->edges);
    free(g);
    it = 0;
}


static AdjList* initAdjList(const Graph *g){
    AdjList *adj = (AdjList*) malloc(sizeof(AdjList));
    adj->V = g->V;
    adj->head = (AdjListNode**) malloc(g->V * sizeof(AdjListNode*));
    for(int i = 0; i < adj->V; ++i){
        adj->head[i] = NULL;
    }

    return adj;
}

AdjList* createAdjList(const Graph *g){
    AdjList *adj = initAdjList(g);

    for(int i = 0; i < g->E; ++i){
        int x = g->edges[i].x;
        int y = g->edges[i].y;

        AdjListNode *node = (AdjListNode*) malloc(sizeof(AdjListNode));
        node->y = g->edges[i].y;
        node->next = adj->head[x];
        adj->head[x] = node;

        node = (AdjListNode*) malloc(sizeof(AdjListNode));
        node->y = g->edges[i].x;
        node->next = adj->head[y];
        adj->head[y] = node;
    }

    return adj;
}

void deleteAdjList(AdjList *adj){
    for(int i = 0; i < adj->V; ++i){
        AdjListNode *tracer = adj->head[i];
        while(tracer){
            AdjListNode *_tmp = tracer;
            tracer = tracer->next;
            free(_tmp);
        }
    }
    free(adj->head);
    free(adj);
}

void printAdjList(const AdjList *adj){
    for(int i = 0; i < adj->V; ++i){
        AdjListNode *tracer = adj->head[i];
        printf("%d ", i);
        while(tracer){
            printf("-> %d ", tracer->y);
            tracer = tracer->next;
        }
        putchar('\n');
    }
}


static AdjMatrix* initAdjMatrix(int V){
    AdjMatrix *matrix = (AdjMatrix*) malloc(sizeof(AdjMatrix));
    matrix->V = V;
    matrix->m = (int**) malloc(V * sizeof(int*));
    for(int i = 0; i < V; ++i){
        matrix->m[i] = (int*) calloc(sizeof(int), V);
    }

    return matrix;
}

AdjMatrix* createAdjMatrix(const Graph *g){
    AdjMatrix *matrix = initAdjMatrix(g->V);

    for(int i = 0; i < g->E; ++i){
        matrix->m[g->edges[i].x][g->edges[i].y] = 1;
        matrix->m[g->edges[i].y][g->edges[i].x] = 1;
    }

    return matrix;
}

static int** readArr(int *V){
    printf("Enter the number of Vertices: ");
        scanf("%d", V);
        getchar();
    int **arr = (int**) malloc(*V * sizeof(int*));
    for(int i = 0; i < *V; ++i){
        arr[i] = malloc(*V * sizeof(int));
    }
    
    printf("Enter the Matrix:\n");
    for(int i = 0; i < *V; ++i){
        printf("[%d] [0] ", i);
        for(int j = 0; j < *V; ++j){
            if(j){
                printf("    [%d] ", j);
            }
            scanf("%d", &arr[i][j]);
            getchar();
        }
        putchar('\n');
    }

    return arr;
}

static void freeArr(int **arr, int V){
    for(int i = 0; i < V; ++i){
        free(arr[i]);
    }
    free(arr);
}

AdjMatrix* createAdjMatrixFromArr(void){
    int V = 0;
    int **arr = readArr(&V);
    
    AdjMatrix *matrix = initAdjMatrix(V);
    matrix->V = V;
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            matrix->m[i][j] = arr[i][j];
        }
    }

    freeArr(arr, V);
    return matrix;
}

void deleteAdjMatrix(AdjMatrix *matrix){
    for(int i = 0; i < matrix->V; ++i){
        free(matrix->m[i]);
    }
    free(matrix->m);
    free(matrix);
}

void printAdjMatrix(const AdjMatrix *matrix){
    int line = 1;
    for(int i = 0; i < matrix->V; ++i){
        if(line){
            printf("   ");
            for(int j = 0; j < matrix->V; ++j){
                printf("%d ", j);
            }
            putchar('\n');
            printf("  ");
            for(int j = 0; j < 2*matrix->V; ++j){
                putchar('-');
            }
            putchar('\n');
            line = 0;
        }
        printf("%d| ", i);
        for(int j = 0; j < matrix->V; ++j){
            printf("%d ", matrix->m[i][j]);
        }
        putchar('\n');
    }
}

Graph* createGraphFromAdjMatrix(const AdjMatrix *matrix){
    int E = 0;
    for(int i = 0; i < matrix->V; ++i){
        for(int j = i; j < matrix->V; ++j){
            if(matrix->m[i][j]) ++E;        
        }
    }

    Graph *g = initGraph(matrix->V, E);
    for(int i = 0; i < matrix->V; ++i){
        for(int j = i; j < matrix->V; ++j){
            if(matrix->m[i][j]){
                addEdge(g, i, j);
            }        
        }
    }

    return g;
}


static void DFSu(AdjList *adj, int *arr, int node, int *count){
    arr[node] = 1;
    *count += 1;
    printf("%d ", node);

    AdjListNode *tracer = adj->head[node];
    while(tracer){
        if(!arr[tracer->y]){
            DFSu(adj, arr, tracer->y, count);
        }
        tracer = tracer->next;
    }
}

int DFS(Graph *g, int node){
    AdjList *adj = createAdjList(g);
    int *arr = (int*) calloc(sizeof(int), g->V);
    // printAdjList(adj);

    int count = 0;
    DFSu(adj, arr, node, &count);
    putchar('\n');

    free(arr);
    deleteAdjList(adj);

    return count;
}

int findGradeOfNode(Graph *g, int node){
    AdjList *adj = createAdjList(g);

    int count = 0;
    AdjListNode *tracer = adj->head[node];
    while(tracer){
        count++;
        tracer = tracer->next;
    }

    deleteAdjList(adj);
    return count;
}


typedef struct Queue{
    int x;
    struct Queue *next;
} Queue;

typedef struct QLimits{
    Queue *head;
    Queue *tail;
} QLimits;

static QLimits* createQueue(void){
    QLimits *ql = (QLimits*) malloc(sizeof(QLimits));
    ql->head = NULL;
    ql->tail = NULL;

    return ql;
}

static Queue* newQNode(int x){
    Queue *node = (Queue*) malloc(sizeof(Queue));
    node->x = x;
    node->next = NULL;

    return node;
}

static void Enqueue(QLimits *ql, Queue *q){
    if(!ql->head){
        ql->head = ql->tail = q;
    } else{
        ql->tail = ql->tail->next = q;
    }
}

static int Dequeue(QLimits *ql){
    if(!ql->head){
        return -1;
    } else{
        int x = ql->head->x;
        Queue *_toDelete = ql->head;
        ql->head = ql->head->next;
        
        free(_toDelete);
        return x;
    }
}

static int isEmptyQ(QLimits *ql){
    if(!ql->head){
        return 1;
    }
    return 0;
}

static void deleteQueue(QLimits *ql){
    Queue *tracer = ql->head,
            *_toDelete;
    
    while(tracer){
        _toDelete = tracer;
        tracer = tracer->next;
        free(_toDelete);
    }
    free(ql);
}

static void BFSu(AdjList *adj, QLimits *ql, int *arr, int node){
    arr[node] = 1;
    Enqueue(ql, newQNode(node));
    
    while(!isEmptyQ(ql)){
        int x = Dequeue(ql);
        AdjListNode *tracer = adj->head[x];
        printf("%d ", x);
        
        while(tracer){
            if(!arr[tracer->y]){
                arr[tracer->y] = 1;
                Enqueue(ql, newQNode(tracer->y));
            }
            tracer = tracer->next;
        }
    }
}

void BFS(Graph *g, int node){
    AdjList *adj = createAdjList(g);
    QLimits *ql = createQueue();
    int *arr = (int*) calloc(sizeof(int), g->V);
    // printAdjList(adj);

    BFSu(adj, ql, arr, node);
    putchar('\n');

    deleteAdjList(adj);
    free(arr);
    deleteQueue(ql);
}


int isConnected(Graph *g){
    if(DFS(g, 0) == g->V){
        return 1;
    }

    return 0;
}


static void printSubG(AdjList *adj, int *arr, int node){
    arr[node] = 1;
    printf("%d ", node);
}

int findSubGraphUnconnected(Graph *g){
    AdjList *adj = createAdjList(g);
    int *arr = (int*) calloc(sizeof(int), g->V);
    // printAdjList(adj);

    int count = 0;
    for(int i = 0; i < g->V; ++i){
        int _tmp = 0;
        if(!arr[i]){
            DFSu(adj, arr, i, &_tmp);
            putchar('\n');
            count++;
        }
    }

    free(arr);
    deleteAdjList(adj);
    return count;
}


static void DFSut(AdjList *adj, int *arr, int node){
    arr[node] = 1;

    AdjListNode *tracer = adj->head[node];
    while(tracer){
        if(!arr[tracer->y]){
            DFSut(adj, arr, tracer->y);
        }
        tracer = tracer->next;
    }
}

int it1 = 0;

static int addEdgeC(Graph *g, int x, int y){
    if(it1 >= g->E){
        return 0;
    }

    g->edges[it1].x = x;
    g->edges[it1].y = y;
    ++it1;
    
    return 1;
}

Graph* connectUnconnectedG(Graph *g){
    AdjList *adj = createAdjList(g);
    int *arr = (int*) calloc(sizeof(int), g->V);
    // printAdjList(adj);

    int count = 0;
    for(int i = 0; i < g->V; ++i){
        int _tmp = 0;
        if(!arr[i]){
            DFSut(adj, arr, i);
            count++;
        }
    }

    Graph *gResult = initGraph(g->V, g->E + (count-1));
    for(int i = 0; i < g->E; ++i){
        addEdgeC(gResult, g->edges[i].x, g->edges[i].y);
    }

    // reset arr back to 0
    for(int i = 0; i < g->V; ++i){
        arr[i] = 0;
    }

    for(int i = 0; i < g->V; ++i){
        int _tmp = 0;
        if(!arr[i]){
            if(i){
                addEdgeC(gResult, 0, i);
            }
            DFSut(adj, arr, i);
        }
    }

    free(arr);
    deleteAdjList(adj);

    return gResult;
}


static void DFSuS(AdjList *adj, int *arr, int node){
    arr[node] = 1;
    printf("%d ", node);

    AdjListNode *tracer = adj->head[node];
    while(tracer){
        if(!arr[tracer->y]){
            DFSuS(adj, arr, tracer->y);
        }
        tracer = tracer->next;
    }
}


void printSubGraphOfConnectedG(Graph *g){
    AdjList *adj = createAdjList(g);
    srand((unsigned int) time(0));
    int *arr = (int*) calloc(sizeof(int), g->V);
    int x = random() % g->V;
    arr[x] = 1;
    // printAdjList(adj);
    
    DFSuS(adj, arr, (g->V + (2 * x)) % g->V);
    putchar('\n');

    free(arr);
    deleteAdjList(adj);
}