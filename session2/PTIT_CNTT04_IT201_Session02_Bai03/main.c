#include <stdio.h>

int main(void) {
    int n ;
    int arr[100];
    do {
        printf("moi ban nhap so long phan tu trong mang : ");
        scanf("%d", &n);
    }while (n < 0 || n > 100);
    arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu [%d] vao mang : " , i);
        scanf("%d", &arr[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        printf("phan tu [%d] : %d\n", i, arr[i]);
    }
    return 0;
}