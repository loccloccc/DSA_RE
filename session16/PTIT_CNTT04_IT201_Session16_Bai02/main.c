#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Quere {
    Node* front;
    Node* rear;
}Quere;
Quere* createQuere() {
    Quere* newQuere = (Quere*)malloc(sizeof(Quere));
    newQuere->front = newQuere->rear = NULL;
    return newQuere;
}
void enQuere(Quere* q , int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (q->front ==NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear;
}
int main(void) {
    Quere *q = createQuere();
    enQuere(q, 10);
    printf("Hello, World!\n");
    return 0;
}