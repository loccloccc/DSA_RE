#include <stdio.h>

int sumArr(int arr[] , int i , int size) {
    if (i==size) return 0;
    return arr[i] + sumArr(arr,i+1,size);
}

int main(void) {
    int n;
    do {
        printf("nhap n : ");
        scanf("%d", &n);
    }while (n<0 || n > 1000);
    int arr[n];
    printf("nhap mang :\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = " , i);
        scanf("%d", &arr[i]);
    }
    printf("\n in mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    int res = sumArr(arr, 0,n);
    printf("%d",res);
    return 0;
}