#include <stdio.h>

int linearchSearch(int arr[] , int n , int value) {
    for (int i = 0 ; i < n ; i++) {
        if (arr[i]==value) {
            return i+1;
        }
    }
    return -1;
}


int main(void) {
    int n ;
    do {
        printf("nhap do dai mang : ");
        scanf("%d",&n);
    }while (n < 0 || n > 1000);
    int arr[n];
    printf("\nnhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang : \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int value ;
    printf("nhap gia tri muon tim : ");
    scanf("%d",&value);
    int res = linearchSearch(arr,n,value);
    if (res!=-1) {
        printf("vi tri thu :%d " , res);
    }else {
        printf("khong ton tai phan tu");
    }
    return 0;
}