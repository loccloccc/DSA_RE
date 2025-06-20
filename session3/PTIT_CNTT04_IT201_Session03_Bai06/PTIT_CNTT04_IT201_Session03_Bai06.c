#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n , m ;
    printf("nhap do dai mang : ");
    scanf("%d", &n);
    int *arrPtr = (int*) malloc(n*sizeof(int));
    if(arrPtr == NULL) {
        printf("loi");
        return;
    }
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] : ", i);
        scanf("%d", &arrPtr[i]);
    }
    printf("in mang 1\n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d",arrPtr[i]);
    }
    printf("\n");
    printf("nhap so luong phan tu them : ");
    scanf("%d", &m);
    arrPtr = (int*) realloc(arrPtr,(m+n)*sizeof(int));
    for (int i = 0 ; i < m ; i++) {
        printf("arr[%d] : ", n+i);
        scanf("%d", &arrPtr[n+i]);
    }
    printf("in mang 2\n");
    for (int i = 0 ; i < m+n ; i++) {
        printf("%d ",arrPtr[i]);
    }
    free(arrPtr);
    return 0;
}