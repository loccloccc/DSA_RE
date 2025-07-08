#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->cap = cap;
    stack->arr = (char*)malloc(sizeof(char) * cap);
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->cap - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int push(Stack *stack , char value) {
    if (isFull(stack)) return 0;
    stack->arr[++stack->top] = value;
    return 1;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}
int isPalindrome(char* str) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(stack)) {
            free(stack->arr);
            free(stack);
            return 0;
        }
    }

    free(stack->arr);
    free(stack);
    return 1;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
