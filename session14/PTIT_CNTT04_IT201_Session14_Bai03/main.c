#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
typedef struct Stack {
    Node* head;
}Stack;
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}
void push(Stack* stack , int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->head;
    stack->head = newNode;
}
void scan(Stack* stack) {
    int n;
    printf("nhap so luong node vao stack : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("nhap node thu %d vao stack  : " , i+1);
        scanf("%d", &data);
        push(stack, data);
    }
}
void display(Stack* stack) {
    if (stack->head == NULL) {
        printf("stack rong");
        return ;
    }
    Node* current = stack->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(void) {
    Stack* stack = createStack();
    scan(stack);
    display(stack);
    free(stack->head);
    free(stack);
    printf("Hello, World!\n");
    return 0;
}