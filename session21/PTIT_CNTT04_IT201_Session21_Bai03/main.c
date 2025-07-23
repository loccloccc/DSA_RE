#include <stdio.h>

#define MAX 3


void add(int graph[MAX][MAX] , int frist , int last) {
    graph[frist][last] = 1;
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
    int frist , last;
    scanf("%d %d", &frist , &last);
    add(graph, frist , last);
    print(graph);
    return 0;
}