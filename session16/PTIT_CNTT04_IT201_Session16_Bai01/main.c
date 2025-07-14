#include <stdio.h>
#include <stdlib.h>

// tao danh sach lien ket
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
// tao quere
typedef struct Quere {
    Node* front;
    Node* rear;
}Quere;
Quere* createQuere() {
    Quere* newQuere = (Quere*)malloc(sizeof(Quere));
    newQuere->front = newQuere->rear = NULL;
    return newQuere;
}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}