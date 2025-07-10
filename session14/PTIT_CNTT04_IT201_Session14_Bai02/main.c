#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack{
    Node* head;
}Stack;

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

Stack* push(Stack* stack , int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}
int main(void) {
    Stack* stack = createStack();
    int n ;
    printf("nhap so luong phan tu node vao stack : ");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int val;
        printf("phan tu node thu %d : " , i+1);
        scanf("%d" , &val);
        push(stack,val);
    }
    printf("\nin mang\n");
    for (int i = n ; i > 0 ; i--) {
        printf("%d " , stack->head->data);
        stack->head = stack->head->next;
    }
    printf("Hello, World!\n");
    free(stack->head);
    free(stack);
    return 0;
}