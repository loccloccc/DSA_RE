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

void printList(Node* head) {
    Node* node = head;
    while (node!= NULL) {
        printf("%d ->" , node-> data);
        node = node-> next;
    }
    printf("NULL\n");
}

Node* deleteAtLast(Node* head) {
    if (head == NULL) return NULL;

    if (head->next ==NULL) {
        free(head);
        return NULL;
    }

    Node* node = head;
    while (node->next->next != NULL) {
        node = node-> next;
    }

    Node* deleteNode = node->next;
    node->next = NULL;
    free(deleteNode);
    return head;
}
int main(void) {
    Node* head = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(head);
    deleteAtLast(head);
    printList(head);
    return 0;
}