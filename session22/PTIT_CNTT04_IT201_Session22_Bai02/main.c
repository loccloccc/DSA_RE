#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
}Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int**)malloc(V*sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V,sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int first , int last) {
    graph->matrix[first][last] = 1;
    graph->matrix[last][first] = 1;
}
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d : ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
            }
        }
        printf("\n");
    }
}

int main(void) {
    int n ;
    printf("nhap vao so dinh : ");
    scanf("%d", &n);
    Graph* graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}