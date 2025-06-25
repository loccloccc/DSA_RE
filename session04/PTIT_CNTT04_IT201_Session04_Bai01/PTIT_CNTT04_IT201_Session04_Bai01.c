#include <stdio.h>

int main(void) {
    int n;
    do {
        printf("nhap do dai mang: ");
        scanf("%d",&n);
    }while (n<0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i <n ; i++) {
        printf("arr[%d] = ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("in mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    int k ;
    printf("nhap gia tri muon tim: ");
    scanf("%d",&k);
    int check = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i]==k) {
            check=1;
            printf("%d",i);
            break;
        }
    }
    if (check==0) {
        printf("khong tim thay phan tu");
    }
    return 0;
}