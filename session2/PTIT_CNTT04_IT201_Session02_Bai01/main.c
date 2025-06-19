#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int arr[100];
    do {
        printf("moi nhap so luong phan tu ");
        scanf("%d",&n);
    }while (n < 0 || n > 100);
    arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d : " ,i+1);
        scanf("%d",&arr[i]);
    }
    //tìm phần tử lớn nhất trong mảng
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("phan tu lon nhat trong mang : %d " , max);
    return 0;
}
