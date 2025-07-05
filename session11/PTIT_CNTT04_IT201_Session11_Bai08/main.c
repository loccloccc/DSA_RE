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

Node* delAtFirst(Node* head ){
    if(head==NULL) return NULL;
    Node* temp = head;
    head = head->next;//co the NULL
    if(head!=NULL) head->prev=NULL;
    free(temp);
    return head;

}
Node* delAtLast(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}
Node* delAtIndex(Node* head, int index){
    if(index<0 || index>lenNode(head)-1) return NULL;
    if(index==0) return delAtFirst(head);
    if(index==lenNode(head)) return delAtLast(head);
    Node* current = head;
    for(int i = 0 ; i < index ; i++){
        current = current->next;
    }
    Node* prev = current->prev;
    Node* next = current->next;
    Node* temp = current;
    prev->next = next;
    next->prev = prev;
    free(temp);
    return head;
}

int main(void) {
    Node* head = createNode(1);
    Node* head1 = createNode(2);
    Node* head2 = createNode(3);
    Node* head3 = createNode(4);
    Node* head4 = createNode(5);
    // head <-> head1 <-> head2...
    head->next = head1;
    head1->prev = head;
    head1->next = head2;
    head2-> prev = head1;
    head2-> next = head3;
    head3-> prev = head2;
    head3->next = head4;
    head4->prev = head3;
    printList(head);
    int index ;
    printf("nhap vi tri:");
    scanf("%d", &index);
    head = delAtIndex(head, index);
    printList(head);
    printf("Hello, World!\n");
    return 0;
}