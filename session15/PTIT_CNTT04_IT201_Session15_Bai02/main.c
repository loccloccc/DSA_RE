#include <stdio.h>
#include <stdlib.h>

typedef struct Quere {
    int *arr;
    int rear;
    int fornt;
    int cap;
}Quere;
Quere* createQuere(int cap) {
    Quere *q = (Quere*)malloc(sizeof(Quere));
    q->fornt = 0;
    q->cap = cap;
    q->rear  = -1;
    q->arr = (int*)malloc(sizeof(int) * cap);
    return q;
}
void enQuere(Quere* q , int val) {
    if (q->rear == q->cap - 1) return;
    q->rear = q->rear + 1;
    q->arr[q->rear] = val;
}
void disQuere(Quere* q) {
    if (q->fornt > q->rear) return;
    for (int i = q->fornt ; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n ;
    printf("nhap so luong phan tu : ");
    scanf("%d", &n);
    Quere *q = createQuere(n);
    printf("nhap gia tri .\n");
    for (int i = 0 ; i < n ; i++) {
        int val;
        printf("phan tu thu %d : " , i + 1);
        scanf("%d", &val);
        enQuere(q, val);
    }
    printf("in phan tu \n");
    disQuere(q);
    free(q->arr);
    free(q);
    return 0;
}