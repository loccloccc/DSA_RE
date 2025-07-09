#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
}Stack;

Stack* createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->cap = cap;
    stack->arr = (int*)malloc(sizeof(int) * cap);
    return stack;
}

int isFull(Stack* stack) {
    if (stack->top == stack->cap-1) return 1;
    else return 0;
}

int push(Stack *stack , int value) {
    if (isFull(stack)) return 0;
    stack->top = stack->top + 1;
    stack->arr[stack->top] = value;
    return 1;
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) return 1;
    else return 0;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No element in stack");
        return 0;
    };
    return stack->arr[stack->top--];
}


int main(void) {
    int n ;
    printf("Nhap n : ");
    scanf("%d", &n);
    Stack* stack = createStack(n);
    if (n>0) {
        printf("nhap phan tu vao stack : \n");
        int value;
        for (int i = 0; i < n; i++) {
            scanf("%d",&value);
            push(stack,value);
        }
    }
    printf("%d\n" , pop(stack));
    free(stack);
    free(stack->arr);
    return 0;
}