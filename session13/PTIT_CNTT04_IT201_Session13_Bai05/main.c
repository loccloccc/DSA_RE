#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;
Stack* createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->cap = cap;
    stack->arr = (int*)malloc(sizeof(int) * cap);
    return stack;
}

// Kiểm tra đầy
int isFull(Stack* stack) {
    return stack->top == stack->cap - 1;
}
int push(Stack *stack , int value) {
    if (isFull(stack)) return 0;
    stack->arr[++stack->top] = value;
    return 1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No element in stack\n");
        return 0;
    }
    return stack->arr[stack->top--];
}
void reverseArray(int* arr, int n) {
    Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    free(stack->arr);
    free(stack);
}

int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n > 0) {
        int* arr = (int*)malloc(sizeof(int) * n);

        printf("Nhap cac phan tu:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        reverseArray(arr, n);

        printf("Mang sau khi dao nguoc:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    } else {
        printf("So luong phan tu khong hop le.\n");
    }

    return 0;
}
