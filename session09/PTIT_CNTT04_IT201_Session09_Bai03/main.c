#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* creatNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node ->data = data;
    node -> next=NULL;
    return node;
}

void check(Node *head , int n) {
    Node *creat = head;
    while (head!=NULL) {
        if (head->data == n) {
            printf("TRUE");
            return;
        }
        head = head -> next;
    }
    printf("FALSE");
}
int main(void) {
    Node *head =NULL;
    Node *node1 = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);
    Node *node6 = creatNode(6);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    int n ;
    printf("nhap n:");
    scanf("%d",&n);
    check(head,n);
    return 0;
}