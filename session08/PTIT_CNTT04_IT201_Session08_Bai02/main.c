#include <stdio.h>
int binariSearch(int arr[] , int n , int value) {
    int left = 0 ;
    int right = n -1;
    while (left<=right) {
        int mid = (left + right)/2;
        if (arr[mid] == value) {
            return mid+1;
        }else if (arr[mid] < value) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return -1;
}
int main(void) {
    int n  ;
    do{
        printf("nhap do dai mang:");
        scanf("%d", &n);
    }while(n<0);
    int arr[n];
    printf("\n nhap mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n in mang \n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    int value;
    printf("nhap gia tri ban muon tim kiem :");
    scanf("%d", &value);
    int result = binariSearch(arr, n, value);
    if (result == -1) {
        printf("khong ton tai");
    }else {
        printf("vi tri thu %d ",result);
    }
    return 0;
}