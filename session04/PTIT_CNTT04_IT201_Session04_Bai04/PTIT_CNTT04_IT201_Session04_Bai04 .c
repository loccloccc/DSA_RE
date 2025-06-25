#include <stdio.h>

int main(void) {
    int n ;
    do {
        printf("nhap do dai mang:");
        scanf("%d",&n);
    }while (n <0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d]",i);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int k , check = 0, index ;
    printf("nhap gia tri:");
    scanf("%d",&k);
    for (int i = 0 ; i < n ;i++) {
        if (arr[i]==k) {
            check = 1;
            index = i ;
            //printf("%d",i);
        }
    }
    if (check!=0) {
        printf("vi tri gia tri %d ban muon tim trong mang : %d",k,index);
    }else {
        printf("khong tim thay phan tu");
    }
    return 0;
}