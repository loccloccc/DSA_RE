#include <stdio.h>
#include <stdlib.h>

typedef struct Quere {
    int *arr;
    int front;
    int rear;
    int cap;

}Quere;

Quere *createQuere(int cap) {
    Quere *q = (Quere *) malloc(sizeof(Quere *));
    q->arr = (int *) malloc(cap * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
};

void enQuere(Quere* q , int val) {
    if (q->rear == q->cap - 1) return;
    q->rear = q->rear + 1;
    q->arr[q->rear] = val;
}

void displayQuere(Quere* q) {
    if (q->front > q->rear) return;
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main(void) {
    int n;
    printf("nhap so luong Quere : ");
    scanf("%d", &n);
    if (n <= 0 ) {
        printf("so luong nhap khong hop le");
    }else {
        Quere *q = createQuere(n);
        printf("nhap gia tri \n");
        for (int i = 0 ; i < n ; i++) {
            int val;
            printf("phan tu thu %d : " , i + 1);
            scanf("%d", &val);
            enQuere(q,val);
        }
        displayQuere(q);
        free(q->arr);
        free(q);
    }
    printf("Hello, World!\n");
    return 0;
}