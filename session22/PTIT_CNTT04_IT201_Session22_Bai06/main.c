#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int** matrix;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

void printGraph(Graph* graph) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void DFSUtil(Graph* g, int src, int* visited) {
    printf("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < g->V; i++) {
        if (g->matrix[src][i] == 1 && visited[i] == 0) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int src) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    printf("Duyet DFS tu dinh %d: ", src);
    DFSUtil(g, src, visited);
    printf("\n");
    free(visited);
}

// Hàm main
int main(void) {
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    Graph* graph = createGraph(V);

    printf("Nhap so canh: ");
    scanf("%d", &E);

    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(graph, u, w);
    }

    printGraph(graph);

    int src;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &src);
    DFS(graph, src);

    return 0;
}
