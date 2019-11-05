#pragma once


typedef struct Edge Edge;
typedef struct Graph Graph;
typedef struct AdjList AdjList;
typedef struct AdjMatrix AdjMatrix;


Graph* initGraph(int V, int E);
void addEdge(Graph *g, int x, int y);
int removeEdge(Graph *g, int x, int y);
void printGraph(Graph *g);
void deleteGraph(Graph *g);

AdjList* createAdjList(const Graph *g);
void deleteAdjList(AdjList *adj);
void printAdjList(const AdjList *adj);

AdjMatrix* createAdjMatrix(const Graph *g);
AdjMatrix* createAdjMatrixFromArr(void);
void deleteAdjMatrix(AdjMatrix *matrix);
void printAdjMatrix(const AdjMatrix *matrix);
Graph* createGraphFromAdjMatrix(const AdjMatrix *matrix);

int DFS(Graph *g, int node);
void BFS(Graph *g, int node);
int findGradeOfNode(Graph *g, int node);

int isConnected(Graph *g);
int findSubGraphUnconnected(Graph *g);

Graph* connectUnconnectedG(Graph *g);
void printSubGraphOfConnectedG(Graph *g);