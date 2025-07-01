#include <stdio.h>


void insertionSort(int arr[] , int n) {
    for (int i = 0 ; i < n ; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]>key) {
            arr[j + 1 ] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void) {
    int n ;
    do {
        printf("nhap n:");
        scanf("%d",&n);
    }while(n<=0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang 1 :\n");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("\n in kham 2 :\n");
    printArray(arr,n);
    return 0;
}