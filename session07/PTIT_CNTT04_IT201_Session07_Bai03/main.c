#include <stdio.h>

void inseertionSort(int arr[] , int size) {
    for (int i = 0  ; i < size ; i++) {
        int key = arr[i];
        int j = i -1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}


void printArr(int arr[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%d ", arr[i]);
    }
}
int main(void) {
    int n ;
    do {
        printf("nhap do dai mang : ");
        scanf("%d",&n);
    }while (n < 0 );
    int arr[n];
    printf("nhap mang :\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang lan 1 :");
    printArr(arr,n);
    inseertionSort(arr,n);
    printf("\n in mang lan 2 :");
    printArr(arr,n);
    return 0;
}