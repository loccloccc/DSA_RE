#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// xay dung ham doi
typedef struct Quere {
    Node** arr;
    int cap;
    int front;
    int rear;
}Quere;
// khoi tao ham doi
Quere *createQuere(int cap) {
    Quere* temp = (Quere*)malloc(sizeof(Quere));
    temp->cap = cap;
    temp->front = 0;
    temp->rear = -1;
    temp->arr = (Node**)malloc(sizeof(Node*) * cap);
    return temp;
}
int isEmpty(Quere *q) {
    if (q->front > q->rear) return 1;
    return 0;
}
int isFull(Quere *q) {
    if (q->rear == q->cap - 1) return 1;
    return 0;
}
// them
void enQueue(Quere *q, Node* data) {
    if (isFull(q)) return;
    q->rear++;
    q->arr[q->rear] = data;
}
// lay
Node* deQueue(Quere *q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}
int check(Node* node , int value) {
    if (node == NULL) return 0;
    Quere* q = createQuere(100);
    enQueue(q, node);
    while (!isEmpty(q)) {
        Node* temp = deQueue(q);
        if (temp->data == value) {
            return 1;
        }
        if (temp->left) enQueue(q, temp->left);
        if (temp->right) enQueue(q, temp->right);
    }
    return 0;
}
int main(void) {
    Node* root = NULL;
    root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    Node* node5 = createNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    if (check(root, n)) {
        printf("TRUE");
    }else {
        printf("FALSE");
    }
    return 0;
}