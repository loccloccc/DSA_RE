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

void addEdge(Graph *g, int u, int v) {
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}
void print(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}
int countTop(Graph* g , int k) {
    int count = 0;
    for (int i = 0; i < g->V; i++) {
        if (g->matrix[k][i] == 1) count++;
    }
    return count;
}
int main(void) {
    int E , V;
    printf("moi nhap so dinh :");
    scanf("%d" , &V);
    Graph *graph = createGraph(V);
    printf("moi nhap so canh : ");
    scanf("%d" , &E);
    for (int i = 0; i < E; i++) {
        int u , v;
        scanf("%d %d" , &u, &v);
        addEdge(graph, u, v);
    }
    print(graph);
    int k ;
    printf("nhap so k : ");
    scanf("%d", &k);
    printf("ket qua : %d ",countTop(graph, k));

    return 0;
}