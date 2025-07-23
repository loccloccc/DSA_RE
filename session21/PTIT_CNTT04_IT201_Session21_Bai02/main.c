#include <stdio.h>
#define MAX 4
void add(int a[MAX][MAX] , int firstNode , int lastNode) {
    a[firstNode][lastNode] = 1;
    a[lastNode][firstNode] = 1;
}
void print(int a[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", a[i][j]);
        }
    printf("\n");
    }
}

int main(void) {
    int a[MAX][MAX] = {{0}};
    int firstNode, lastNode;
    for(int i = 0; i < 4; i++) {
        printf("lan %d : " , i+1);
        scanf("%d", &firstNode);
        scanf("%d", &lastNode);
        add(a, firstNode, lastNode);
    }
    print(a);
    return 0;
}