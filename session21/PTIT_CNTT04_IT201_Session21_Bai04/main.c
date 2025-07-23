#include <stdio.h>

#define MAX 3

void add(int graph[MAX][MAX] , int first , int last) {
    graph[first][last] = 1;
    graph[last][first] = 1;
}

void print(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int graph[MAX][MAX] = {{0}};
    int first, last;
    for (int i = 0; i < MAX; i++) {
        printf("nhap la %d " , i+1);
        scanf("%d", &first);
        scanf("%d", &last);
        add(graph, first, last);
    }
    print(graph);
    return 0;
}