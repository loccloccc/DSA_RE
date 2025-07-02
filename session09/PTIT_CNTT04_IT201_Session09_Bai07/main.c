#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* creatNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node->next = NULL;
    return node;
}

int length(Node* head) {
    Node* node = head;
    int count = 0;
    while (node!=NULL) {
        count++;
        node = node->next;
    }
    return count;
}
Node* addFrist(Node* head , int data ) {
    Node* newNode = creatNode(data);
    newNode->next = head;
    return newNode;
}

Node* addLast(Node* head , int data ) {
    Node* newNode = creatNode(data);
    if (head==NULL) return NULL;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* addAtIndex(Node* head , int data, int index) {
    if (index < 0 || index>length(head)-1) return NULL;
    if (index==0) return addFrist(head,data);
    if (index==length(head)-1) return addLast(head,data);

    Node* current = head;
    for (int i = 0 ; i < index -1 ; i++) {
        current = current->next;
    }
    Node* newNode = creatNode(data);
    Node* nextNode = current->next;
    newNode->next = nextNode;
    current->next = newNode;
    return head;

}

void display(Node* head) {
    Node* node = head;
    while (node!=NULL) {
        printf("%d -> " , node->data);
        node = node-> next;
    }
    printf("NULL\n");
}
int main(void) {
    Node* head =NULL;
    Node* node1 = creatNode(1);
    Node* node2 = creatNode(2);
    Node* node3 = creatNode(3);
    Node* node4 = creatNode(4);
    Node* node5 = creatNode(5);

    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;

    int index , value;
    printf("nhap vi tri muon them:");
    scanf("%d",&index);
    printf("nhap gai tri muon them:");
    scanf("%d",&value);
    head=addAtIndex(head,value,index-1);
    display(head);
    return 0;
}