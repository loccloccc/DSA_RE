#include <stdio.h>
#include <stdlib.h>

typedef  struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = data;
    node->next = NULL;
    return node;
}

void printList(Node* node) {
    Node* temp = node;
    while (temp != NULL) {
        printf("%d -> " , temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

Node* deleteAtValue(Node* head, int value) {
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}
int main(void) {
    Node* head = NULL;
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(20);
    Node* node4 = createNode(50);
    Node* node5 = createNode(20);
    Node* node6 = createNode(70);
    head  = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    printList(head);
    head = deleteAtValue(head , 20);
    printList(head);
    printf("Hello, World!\n");
    return 0;
}