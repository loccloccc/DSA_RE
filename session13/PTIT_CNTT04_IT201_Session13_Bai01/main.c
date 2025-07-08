#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int arr;
    int top;
    int cap;
}Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->cap = size;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

int main(void) {
    Stack* stack = createStack(5);
    free(stack->arr);
    return 0;
}