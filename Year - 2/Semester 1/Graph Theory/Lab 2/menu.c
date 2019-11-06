#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define M 7

static void opt1(Graph *g);
static void opt2(Graph *gg);
static Graph* makeGraphFromInput(void);
static void opt3(Graph *g);
static void opt4(Graph *g);
static void opt5(Graph *g);
static void opt6(Graph *g);


const char m[][255] = {"1. Sa se construiasca matricea de adiacenta",
                        "2. Determinarea muchiilor grafului pronind de la matricea de adiacenta",
                        "3. Determinarea gradului unui varf/nod",
                        "4. Parcurgerea in adancime",
                        "5. Parcurgerea in latime",
                        "6. Verificarea daca graful neorientat este conex",
                        "7. Exit"};


static int getOpt(void){
    int opt;
    printf("\nOptiunea: ");
    if(scanf("%d", &opt) != 1){
        fprintf(stderr, "Optiunea selectata este invalida!\n");
        exit(EXIT_FAILURE);
    }
    getchar();

    return opt;
}

void menu(Graph *g){
    system("clear");
    for(int i = 0; i < M; ++i){
        printf("%s\n", m[i]);
    }

    switch(getOpt()){
        case 1:
            opt1(g);
            break;
        case 2:
            opt2(g);
            break;
        case 3:
            if(!g){
                g = makeGraphFromInput();
            }
            opt3(g);
            break;
        case 4:
            if(!g){
                g = makeGraphFromInput();
            }
            opt4(g);
            break;
        case 5:
            if(!g){
                g = makeGraphFromInput();
            }
            opt5(g);
            break;
        case 6:
            if(!g){
                g = makeGraphFromInput();
            }
            opt6(g);
            break;
        case 7:
            if(g){
                deleteGraph(g);
            }
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
}


static void goBack(void){
    printf("\nEnter to return...");
    getchar();
}

static void opt1(Graph *g){
    system("clear");
    printf("~~~ Matricea de Adiacenta ~~~\n\n");
    
    printf("~~ Creearea Grafului:\n");
    printf("~ Introduceti numarul de Noduri si Muchii: ");
    int V, E;
    scanf("%d %d", &V, &E);
    getchar();

    g = initGraph(V, E);
    printf("Introduceti Muchiile:\n");
    int x, y;
    for(int i = 0; i < E; ++i){
        printf("M[%d]: ", i+1);
        scanf("%d %d", &x, &y);
        getchar();
        addEdge(g, x, y);
    }

    AdjMatrix *adjM = createAdjMatrix(g);
    system("clear");
    printf("~~~ Matricea de Adiacenta ~~~\n\n");    
    printAdjMatrix(adjM);

    
    deleteAdjMatrix(adjM);

    goBack();
    return menu(g);
}

static void opt2(Graph *gg){
    system("clear");
    printf("~~~ Determinarea muchiilor grafului pornind de la Matricea de Adiacenta ~~~\n\n");

    AdjMatrix *adjM = createAdjMatrixFromArr();
    Graph *g = createGraphFromAdjMatrix(adjM);

    printf("Muchiile sunt:\n");
    printGraph(g);


    deleteAdjMatrix(adjM);
    deleteGraph(g);

    goBack();
    return menu(gg);
}

static Graph* makeGraphFromInput(void){
    system("clear");
    printf("~~ Creearea Grafului:\n");
    printf("~ Introduceti numarul de Noduri si Muchii: ");
    int V, E;
    scanf("%d %d", &V, &E);
    getchar();
    
    Graph *g = initGraph(V, E);
    printf("Introduceti Muchiile:\n");
    int x, y;
    for(int i = 0; i < E; ++i){
        printf("M[%d]: ", i+1);
        scanf("%d %d", &x, &y);
        getchar();
        addEdge(g, x, y);
    }

    return g;
}

static void opt3(Graph *g){
    int node;
    system("clear");
    printf("~~~ Determinarea Gradului unui Nod ~~~\n\n");

    printf("Introduceti nodul: ");
    scanf("%d", &node);
    getchar();
    
    printf("Nodul[%d] are Gradul[%d]\n", node, findGradeOfNode(g, node));

    goBack();
    return menu(g);
}

static void opt4(Graph *g){
    system("clear");
    printf("~~~ Parcurgerea in adancime a grafului ~~~\n\n");

    int node;
    printf("Introduceti primul nod: ");
    scanf("%d", &node);
    getchar();

    DFS(g, node);

    goBack();
    return menu(g);    
}

static void opt5(Graph *g){
    system("clear");
    printf("~~~ Parcurgerea in latime a grafului ~~~\n");

    int node;
    printf("Introduceti primul nod: ");
    scanf("%d", &node);
    getchar();

    BFS(g, node);

    goBack();
    return menu(g); 
}

static void opt6(Graph *g){
    int is;
    for(int i = 0; i < 2; ++i){
        system("clear");
        printf("~~~ Verificarea daca Graful este Conex ~~~\n\n");

        if(i)   break;

        is = isConnected(g);
    }
    printf("Graful %s Conex!\n", (is) ? "este" : "NU este");

    if(!is){
        printf("\nSubGrafurile sunt:\n");
        printf("Au fost gasite %d SubGrafuri\n", findSubGraphUnconnected(g));
    } else{
        printf("\nUn SubGraf este:\n");
        printSubGraphOfConnectedG(g);
    }

    goBack();
    return menu(g);
}