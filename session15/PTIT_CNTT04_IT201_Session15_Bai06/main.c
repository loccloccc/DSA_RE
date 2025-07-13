#include <stdio.h>
#include <stdlib.h>

typedef struct Quere {
    int *arr;
    int front;
    int rear ;
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

void enQuere(Quere *q, int val) {
    if (q->rear == q->cap - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear = q->rear + 1;
    q->arr[q->rear] = val;
}



void check(Quere *q) {
    if (q->front > q->rear ) return;
    int count = 0;
    for (int i = q->front; i <= q->rear; i++) {
        if (q->arr[i+1] - q->arr[i] == 1) {
            count++;
        }else {
            break;
        }
    }
   int size = q->rear - q->front;
    printf("%d\n", count);
    printf("%d" , size);
    if (count==size) printf("TRUE");
    else printf("FALSE");
}

int main(void) {
    Quere *q = createQuere(5);
    enQuere(q, 1);
    enQuere(q, 2);
    enQuere(q, 3);
    enQuere(q, 7);
    enQuere(q, 5);
    check(q);
    return 0;
}