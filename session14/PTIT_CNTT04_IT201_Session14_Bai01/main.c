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
    if (newStack==NULL) return NULL;
    newStack->head = NULL;
    return newStack;
}

int main(void) {
    Stack* stack = createStack();
    free(stack->head);
    printf("Hello, World!\n");
    return 0;
}