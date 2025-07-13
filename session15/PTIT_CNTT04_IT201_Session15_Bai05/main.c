#include <stdio.h>
#include <stdlib.h>

typedef struct Quere {
    int *arr;
    int front;
    int rear;
    int cap;
}Quere;

Quere *createQuere(int cap) {
    Quere *q = (Quere *) malloc(sizeof(Quere));
    q->arr = (int *) malloc(cap * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
};
void enQuere(Quere *q , int value) {
    if(q->rear == q->cap - 1) {
        printf("Queue is full\n");
        return;
    }
    q->arr[++q->rear] = value;
}
int getFornt(Quere *q) {
    if(q->front == q->rear + 1) {
        return -1;
    }
    return q->arr[q->front++];
}
int main(void) {
    Quere *q = createQuere(5);
    enQuere(q, 1);
    enQuere(q, 2);
    enQuere(q, 3);
    enQuere(q, 4);
    enQuere(q, 5);
    printf("value = %d \n", getFornt(q));
    return 0;
}