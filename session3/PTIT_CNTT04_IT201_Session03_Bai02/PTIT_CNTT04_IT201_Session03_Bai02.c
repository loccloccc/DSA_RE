#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n ;
    printf("nhap so luong phan tu :");
    scanf("%d", &n);
    if (n<=0) {
        printf("so luong phan tu khong hop le.");
        return;
    }
    int *arrPtr = (int *) malloc(n * sizeof(int));
    if (arrPtr==NULL) {
        printf("loi");
    }
    printf("nhap mang\n");
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d:", i+1);
        scanf("%d", &arrPtr[i]);
    }
    int max = arrPtr[0];
    for (int i = 0 ; i < n; i++) {
        if (arrPtr[i] > max) {
            max = arrPtr[i];
        }
    }
    printf("max = %d ",max);
    free(arrPtr);
    return 0;
}