#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next= NULL;
    return node;
}

void printList(Node* head) {
    Node* node = head;
    while (node!=NULL) {
        printf("%d -> " , node->data);
        node = node -> next;
    }
    printf("NULL\n");
}

Node* addAtLast(Node* head , int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    Node* node = head;
    while (node-> next != NULL) {
        node = node -> next;
    }
    node->next = newNode;
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
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    head = addAtLast(head, n);
    printList(head);
    return 0;
}