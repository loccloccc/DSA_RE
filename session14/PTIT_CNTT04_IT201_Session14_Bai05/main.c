#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

typedef struct Stack {
    Node* head;
}Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = stack->head;
    stack->head = temp;
}
void scan(Stack* stack ) {
    int* arr = (int*)malloc(sizeof(int));
    int n;
    printf("nhap so luong node vao stack : ");
    scanf("%d", &n);
    arr[n];
    printf("nhap vao stack\n");
    for (int i = 0; i < n; i++) {
        int val;
        printf("phan tu node thu %d " , i + 1);
        scanf("%d", &val);
        push(stack, val);
    }
    Node* current = stack->head;
    for (int i = 0; i < n; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    printf("%d" ,arr[n-1]);
}

int main(void) {
    Stack* stack = createStack();
    scan(stack);
    free(stack->head);
    free(stack);
    return 0;
}