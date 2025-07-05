#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
}

void printNode(Node* head){
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* addFirst(Node* head , int data) {
    Node* temp = createNode(data);
    temp->next = head;
    if (head!=NULL) head->prev = temp;
    return temp;
}

int main(void) {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    printNode(node1);
    int n ;
    printf("nhap n:");
    scanf("%d",&n);
    node1 = addFirst(node1,n);
    printNode(node1);
    return 0;
}