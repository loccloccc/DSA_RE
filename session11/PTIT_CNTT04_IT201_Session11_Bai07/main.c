#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node* head){
    Node* current = head;
    printf("NULL <-> ");
    while(current!=NULL){
        printf(" %d  <->" , current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int lenNode(Node* head){
    int len = 0 ;
    Node* node = head;
    while(node!=NULL){
        len++;
        node = node->next;
    }
    return len;
}
Node* addAtFrist(Node* head , int data){
    Node* node = createNode(data);
    node->next = head;
    if(head!=NULL) head->prev = node;
    return node;
}

Node* addAtLast(Node* head , int data){
    Node* node = createNode(data);
    if (head == NULL) return node;
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
    return head;
}

Node* addAtIndex(Node* head , int data , int index){
    if(index<0 || index> lenNode(head)) return NULL;
    if(index==0) return addAtFrist(head,data);
    if(index==lenNode(head)) return addAtLast(head,data);
    Node* current = head;
    for(int i = 0 ; i < index ; i++){
        current = current->next;
    }
    Node* node = createNode(data);
    Node* prev = current->prev;
    node->next = current;
    current->prev=node;
    prev->next = node;
    node->prev = prev;
    return head;

}
int main(void) {
    Node* head = createNode(1);
    Node* head1 = createNode(2);
    Node* head2 = createNode(3);
    Node* head3 = createNode(4);
    Node* head4 = createNode(5);
    head->next = head1;
    head1->prev = head;
    head1->next = head2;
    head2-> prev = head1;
    head2-> next = head3;
    head3-> prev = head2;
    head3->next = head4;
    head4->prev = head3;
    printList(head);
    int index , data;
    printf("nhap vi tri: ");
    scanf("%d", &index);
    printf("nhap gia tri : ");
    scanf("%d", &data);
    head = addAtIndex(head,data, index);
    printList(head);
    printf("Hello, World!\n");
    return 0;
}