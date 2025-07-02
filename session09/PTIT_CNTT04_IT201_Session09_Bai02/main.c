#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
//hàm tạo
Node *creatNode(int data) {
    //cap phat bo nho
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next= NULL;
    return node;
}

//ham in
void printList(Node *x) {
    Node *head = x;
    int count = 1;
    while (x != NULL) {
        printf("Node %d : %d ", count, x->data);
        count++;
        x = x->next;
        printf("\n");
    }
    printf("\n");

}
int main(void) {
    Node *head = NULL;
    Node *node1 = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(head);
    return 0;
}