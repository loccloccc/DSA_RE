#include <stdio.h>
#include <stdlib.h>

typedef struct Quere {
    int *arr;
    int front;
    int rear;
    int cap;
}Quere;

Quere *createQuere(int cap) {
    Quere* q = (Quere*)malloc(sizeof(Quere));
    q->front = 0 ;
    q->rear = -1;
    q->cap = cap;
    q->arr = (int *)malloc(sizeof(int) * cap);
    return q;
};
void enQuere(Quere* q , int value) {
    if (q->rear == q->cap - 1) return;
    q->arr[++q->rear] = value;
}
void isEmpty(Quere *q) {
    if (q->front > q->rear) {
        printf("True");
        return;
    }
    printf("False");
}
int main(void) {
    int n;
    printf("nhap so luong: ");
    scanf("%d", &n);
    Quere *q = createQuere(n);
    if (n <= 0) {
        isEmpty(q);
    }else {
        printf("nhap gia tri : \n");
        for (int i = 0; i < n; i++) {
            int val;
            printf("phan tu thu %d " , i+ 1);
            scanf("%d", &val);
            enQuere(q,val);
        }
        isEmpty(q);
    }
    free(q->arr);
    free(q);
    return 0;
}