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
typedef struct Quere {
    Node* front;
    Node* rear;
}Quere;
Quere* createQuere() {
    Quere *q = (Quere*)malloc(sizeof(Quere));
    q->front = q->rear = NULL;
    return q;
}

void enQuere(Quere *q, int data) {
    Node* node = createNode(data);
    if (node==NULL) return;
    if (q->front == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}
int getQuere(Quere *q) {
    if (q->front == NULL) return -1;
    return q->front->data;
}
void deQuere(Quere *q) {
    if (q->front == NULL) return;
    Node* node = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(node);
}
void printQuere(Quere *q) {
    if (q->front == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* current = q->front;
    while (current!= NULL) {
        printf("%d " , current->data);
        current = current->next;
    }
    printf("\n");
}
int main(void) {
    Quere *q = createQuere();
    enQuere(q, 1);
    enQuere(q, 2);
    enQuere(q, 3);
    printQuere(q);
    printf("Hello, World!\n");
    return 0;
}