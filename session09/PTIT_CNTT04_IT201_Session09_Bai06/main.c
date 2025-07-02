#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printNode(Node* head) {
    Node* node = head;
    while (head!=NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* deleteNodeAtFirst(Node* head) {
    Node* node = head;
    if (node==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main(void) {
    Node* head = NULL;

    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    head = deleteNodeAtFirst(head);
    printNode(head);
    return 0;
}