#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V , sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int u , int v) {
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
typedef struct GraphSignly {
    Graph *graph;
    struct GraphSignly *next;
}GraphSignly;
GraphSignly *createGraphSignly(Graph *graph) {
    GraphSignly *graphSignly = (GraphSignly *)malloc(sizeof(GraphSignly));
    graphSignly->graph = graph;
    graphSignly->next = NULL;
    return graphSignly;
}
void addEdgeSignly(Graph* graph , GraphSignly *graphSignly[]) {
   for (int i = 0; i < graph->V; i++) {
       graphSignly[i] = NULL;
       for (int j = 0; j < graph->V; j++) {
           if (graph->matrix[i][j] == 1) {
               GraphSignly* temp = createGraphSignly(graph);
               temp->next = graphSignly[i];
               graphSignly[i] = temp;
           }
       }
   }
}
void printGraphSignly(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d :" , i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ->" , j );
            }
        }
        printf("NULL\n");
    }
    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    Graph *graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    printGraphSignly(graph);

    return 0;
}