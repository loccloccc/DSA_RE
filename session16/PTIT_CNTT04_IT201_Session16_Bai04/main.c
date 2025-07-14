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
    temp->front = temp->rear = NULL;
    return temp;
}
void enQuere(Quere* q , int data) {
    Node* newNode = createNode(data);
    if (newNode==NULL) return ;
    if (q->front ==NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear;
}
int getQuere(Quere* q) {
    if (q->front == NULL) {
        return -1;
    }
    return q->front->data;
}



int main(void) {
    Quere* q = createQuere();
    enQuere(q, 10);
    enQuere(q, 20);
    if (getQuere(q) == -1) {
        printf("rong");
    }else {
        printf("%d\n", getQuere(q));
    }
    return 0;
}