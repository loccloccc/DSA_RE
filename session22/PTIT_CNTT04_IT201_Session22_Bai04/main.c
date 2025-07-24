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
void add(Graph* g) {
    printf("mhoi nhap : %d x %d \n" , g->V , g->V);
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            scanf("%d", &g->matrix[i][j]);
        }
    }
}
int count(Graph* g) {
    int count = 0;
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            if (g->matrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count/2;
}
int main(void) {
    int n;
    scanf("%d", &n);
    Graph *g = createGraph(n);
    add(g);
    printf("\n%d\n", count(g));
    return 0;
}