#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
}Graph;

Graph* creteGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int**)malloc(V*sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V,sizeof(int));
    }
    return graph;
}
void addEdge(Graph* graph , int src , int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int n ;
    printf("nhap so dinh : ");
    scanf("%d", &n);
    Graph* graph = creteGraph(n);
    int first , last;
    for (int i = 0; i <= n; i++) {
        printf("lan : %d \n" , i + 1);
        printf("first ");
        scanf("%d", &first);
        printf("last ");
        scanf("%d", &last);
        addEdge(graph, first, last);
    }
    printGraph(graph);
    return 0;
}