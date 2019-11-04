#include <stdio.h>
#include <stdlib.h>


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

    for(int i = 0; i < adj->V; ++i){
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

AdjMatrix* createAdjMatrixFromArr(int V, const int **arr){
    AdjMatrix *matrix = initAdjMatrix(V);
    matrix->V = V;
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            matrix->m[i][j] = arr[i][j];
        }
    }

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