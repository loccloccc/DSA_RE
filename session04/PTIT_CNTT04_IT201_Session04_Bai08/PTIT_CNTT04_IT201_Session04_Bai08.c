#include <stdio.h>

int main(void) {
    int n ;
    do {
        printf("nhap n:");
        scanf("%d", &n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]:",i);
        scanf("%d", &arr[i]);
    }
    printf("\nin mang\n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    int k ;
    printf("\nnhap so:");
    scanf("%d",&k);
    int check = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == k) {
            check = 1;
            printf("%d ",i);
        }
    }
    if (check==0) {
        printf("phan tu khong ton tai");
    }
    return 0;
}