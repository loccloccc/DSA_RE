#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node *creatNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void countList(Node *head) {
    Node *current = head ;
    int count = 0;
    while (head!=NULL) {
        count++;
        head = head->next;
    }
    printf("Danh sach lien ket co %d phan tu",count);
}
int main(void) {
    Node *head =NULL;
    Node *node1 = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);
    head=node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    countList(head);
    return 0;
}