#include <stdio.h>
#include <stdlib.h>


typedef struct Quere {
    int *arr;
    int fornt;
    int rear;
    int cap;
}Quere;

Quere *createQuere(int cap) {
    Quere *q = (Quere *) malloc(sizeof(Quere *));
    q->arr = (int *) malloc(cap * sizeof(int));
    q->fornt = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
};


int main(void) {
    return 0;
}