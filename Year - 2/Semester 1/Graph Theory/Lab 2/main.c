#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "graph.h"


int main(void){
    Graph *g = NULL;
    menu(g);
    // Graph *g = initGraph(7, 4);
    // addEdge(g, 0, 1); 
    // addEdge(g, 0, 2); 
    // addEdge(g, 1, 2); 
    // addEdge(g, 2, 0); 
    // addEdge(g, 2, 3); 
    // addEdge(g, 3, 3); 

    // addEdge(g, 0, 1);
    // addEdge(g, 0, 4);
    // addEdge(g, 1, 2);
    // addEdge(g, 1, 3);
    // addEdge(g, 1, 4);
    // addEdge(g, 2, 3);
    // addEdge(g, 3, 4);
    // DFS(g, 2);
    // BFS(g, 0);

    // addEdge(g, 0, 1);
    // addEdge(g, 1, 2);
    // addEdge(g, 2, 3);
    // addEdge(g, 5, 6);
    // printf("\n[%d]\n", findSubGraphUnconnected(g));
    // Graph *gConn = connectUnconnectedG(g);
    // AdjList *adj = createAdjList(gConn);
    // printAdjList(adj);
    // printf("\n[%d]\n", findSubGraphUnconnected(gConn));
    
    // deleteAdjList(adj);
    // deleteGraph(gConn);
    // AdjList *adj = createAdjList(g);
    // printAdjList(adj);

    // AdjMatrix *matrix = createAdjMatrix(g);
    // printAdjMatrix(matrix);
    
    // deleteGraph(g);
    // deleteAdjList(adj);
    // deleteAdjMatrix(matrix);


    // int **arr = (int**) malloc(5 * sizeof(int*));
    // for(int i = 0; i < 5; ++i){
    //     arr[i] = (int*) calloc(sizeof(int), 5);
    // }
    // arr[0][0] = 0; arr[0][1] = 1; arr[0][2] = 0; arr[0][3] = 0, arr[0][4] = 1;
    // arr[1][0] = 1; arr[1][1] = 0; arr[1][2] = 1; arr[1][3] = 1, arr[1][4] = 1;
    // arr[2][0] = 0; arr[2][1] = 1; arr[2][2] = 0; arr[2][3] = 1, arr[2][4] = 0;
    // arr[3][0] = 0; arr[3][1] = 1; arr[3][2] = 1; arr[3][3] = 0, arr[3][4] = 1;
    // arr[4][0] = 1; arr[4][1] = 1; arr[4][2] = 0; arr[4][3] = 1, arr[4][4] = 0;
    
    // AdjMatrix *matrix = createAdjMatrixFromArr();
    // Graph *g = createGraphFromAdjMatrix(matrix);
    // AdjList *adj = createAdjList(g);
    // printAdjList(adj);

    // for(int i = 0; i < 5; ++i){
    //     free(arr[i]);
    // }
    // free(arr);
    // deleteAdjMatrix(matrix);
    // deleteAdjList(adj);
    deleteGraph(g);
    return 0;
}