#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

typedef struct Graph {
    int vertices;
    struct Node** list;
}Graph;
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->list[i] = NULL;
    }
    return graph;
}
void addEdge(Graph* graph, int v , int u) {
    Node* newNode = createNode(u);
    newNode->next = graph->list[v];
    graph->list[v] = newNode;

    newNode = createNode(v);
    newNode->next = graph->list[u];
    graph->list[u] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Node %d:", i);
        Node* temp = graph->list[i];
        while (temp != NULL) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(void) {
    int vertices ;
    printf("nhap so luong dinh:");
    scanf("%d", &vertices);
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}