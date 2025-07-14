#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

typedef struct Quere {
    Node* front;
    Node* rear;
}Quere;

Quere* createQuere() {
    Quere* temp = (Quere*)malloc(sizeof(Quere));
    temp->front = temp->rear =  NULL;
    return temp;
}

void enQuere(Quere* q , int data) {
    Node* newNode = createNode(data);
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear;
}

void deQuere(Quere* q) {
    if (q->front == NULL) {
        printf("rong");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;;
    free(temp);
}

int main(void) {
    Quere* q = createQuere();
    deQuere(q);
    return 0;
}