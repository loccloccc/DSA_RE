#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int* arr;
    int top;
    int cap;
}Stack;

// ham khoi tao stack
Stack* createStack(int cap){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (int*)malloc(sizeof(int) * cap);
    return stack;
}
// ham check xem mang da day chua
int isFull(Stack* stack){
    if(stack->top == stack->cap - 1 ) return 1;
    return 0;
}
// ham them gia tri
char push(Stack* stack , char val){
    if(isFull(stack)) return '\0';
    stack->top = stack->top + 1;
    stack->arr[stack->top] = val;
    return '\1';
}
// ham check xem mang co rong r
int isEmpty(Stack* stack){
    if(stack->top == -1) return 1;
    return 0;
}
// ham lay gia tri
int pop(Stack* stack){
    if(isEmpty(stack)) return '\0';
    char val = stack->arr[stack->top];
    stack->top--;
    return val ;
}

void check(Stack *stack , char str[]){
    for(int i = 0 ; i < strlen(str) ; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(stack,str[i]);
        }else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(isEmpty(stack)){
                printf("FALSE");
                return ;
            }
            char top = pop(stack);
            if((str[i] == ')' && top != '(') || (str[i] == ']' && top != '[') || (str[i] == '}' && top != '{') ){
                printf("FALSE");
                return;
            }
        }
    }
    if(isEmpty(stack)) printf("TRUE");
    else printf("FALSE");

}
int main(){
    char str[100];
    printf("nhap chuoi:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    Stack* stack = createStack(strlen(str));
    printf("%s\n" , str);
    check(stack,str);

    free(stack->arr);
    free(stack);
    return 0 ;
}
