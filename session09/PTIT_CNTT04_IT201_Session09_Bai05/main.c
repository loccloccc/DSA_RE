#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printNode(Node* head) {
    Node* node = head;
    while (node!=NULL) {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

Node* addNodeAtFirst(Node* head , int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}
int main(void) {
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    int n ;
    printf("nhap so bat ki:");
    scanf("%d", &n);
    node1 = addNodeAtFirst(node1, n);
    printNode(node1);
    return 0;
}