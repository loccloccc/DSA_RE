#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *) calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->arr = (int *) malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front++];
    }
    return -1;
}
void BFS(Graph *graph, int src) {
    int *visited = (int *) calloc(graph->V, sizeof(int));
    Queue *queue = createQueue(graph->V);
    enqueue(queue, src);
    visited[src] = 1;
    printf("bat dau duyet BFS tu dinh %d: ", src);
    while (!isEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        for (int i = 0; i < graph->V; i++) {
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    free(queue->arr);
    free(queue);
    free(visited);
}

int main(void) {
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    Graph* graph = createGraph(V);

    printf("Nhap so canh: ");
    scanf("%d", &E);

    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printMatrix(graph);

    int src;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &src);

    BFS(graph, src);

    return 0;
}