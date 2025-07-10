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
}

int push(Stack* stack , int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack* stack) {
    if (stack->head == NULL) {
        return -1;
    }
    Node* valueStack = stack->head;
    int val = valueStack->data;
    stack->head = stack->head->next;
    free(valueStack);
    return val;
}
int main(void) {
    Stack* newStack = createStack();
    int n ;
    printf("nhap so luong node :");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int val;
        printf("phan tu node thu %d : " , i+1);
        scanf("%d", &val);
        push(newStack, val);
    }
    if (pop(newStack)==-1) {
        printf("Stack rong");
    }else {
        printf("phan tu : %d \n" , pop(newStack));
    }
    return 0;
}