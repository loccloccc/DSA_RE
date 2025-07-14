#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node*));
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
    newQuere->front = newQuere->rear =NULL;
    return newQuere;
}

// nhap
void enQuere(Quere* q , int data) {
    Node* n = createNode(data);
    if (n==NULL) return;
    if (q->front ==NULL  ) {
        q->front = q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear;

}
// ham xem phan tu dau
int getQuere(Quere* q) {
    if (q->front == NULL) return -1;
    return q->front->data;
}
int main(void) {
    Quere *q = createQuere();
    enQuere(q, 10);
    enQuere(q, 20);
    enQuere(q, 30);
    printf("%d\n", getQuere(q));
    printf("Hello, World!\n");
    return 0;
}