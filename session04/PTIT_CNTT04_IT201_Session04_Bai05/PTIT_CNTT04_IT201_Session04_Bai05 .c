#include <stdio.h>

int main(void) {
    int n ;
    do {
        printf("nhap do dai mang:");
        scanf("%d",&n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nin mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d " , arr[i]);
    }
    printf("sap xep:\n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            if (arr[i]>arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int k , check = 0;
    printf("nhap gia tri tim kiem: ");
    scanf("%d",&k);
    int left = 0;
    int right = n-1;
    while (left<=right) {
        int mid = (left+right)/2;
        if (arr[mid]==k) {
            check=1;
            break;
        }else if (arr[mid] > k) {
            right = mid -1;
        }else {
            left  = mid + 1;
        }
    }
    if (check==1) {
        printf("phan tu co trong mang");
    }else {
        printf("phan tu khong co trong mang");
    }
    return 0;
}