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
    return temp;
}

void printList(Node* head) {
    Node* current = head;
    printf("NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* deleteValue(Node* head , int value) {
    //ktra rong
    Node* current = head;
    if (current==NULL) return NULL;
    if (current->data == value) {
        Node* temp = current;
        current = current->next;
        if (current!=NULL) {
            current->prev = NULL;
        }
        free(temp);
    }
    while (current != NULL) {
        if (current->data == value) {
            Node* temp = current;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            current = current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
}
int main(void) {
    Node* node1 = createNode(1);
    Node* node2 = createNode(5);
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

    printList(node1);
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    node1 = deleteValue(node1, n);
    printList(node1);
    return 0;
}