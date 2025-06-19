#include <stdio.h>

int main(void) {
    int n ;
    int arr[100];
    int value , count = 0;
    do {
        printf("moi ban nhap so luong phan tu : ");
        scanf("%d",&n);
    }while ( n < 0 || n > 100);
    arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu [%d] vao mang : " , i+1);
        scanf("%d",&arr[i]);
    }
    printf("moi ban nhap phan tu muon dem : ");
    scanf("%d",&value);
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    printf("so %d xuat hien %d trong mang." , value , count);
    return 0;
}