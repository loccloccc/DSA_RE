#include <stdio.h>
void swap(int arr[] , int i , int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partitions(int arr[], int left, int right) {
    int pivot = arr[left];
    int count = 0;
    for (int i = left + 1 ; i < right ; i++ ) {
        if (arr[i] < pivot) {
            count++;
        }
    }
    int indexPivod = left + count;
    swap(arr , left , indexPivod);
    int i = left ;
    int j = right;
    while (i < indexPivod && j < indexPivod) {
        while (arr[i]<pivot) {
            i++;
        }
        while (arr[j]>pivot) {
            j++;
        }
        if (i < indexPivod && j > indexPivod ) {
            swap(arr , i , j);
        }
    }
    return indexPivod;
}
void quickSort(int arr[] , int left , int right) {
    if (left >= right) return;
    int pivot = partitions(arr,left,right);
    quickSort(arr,left,pivot);
    quickSort(arr,pivot + 1,right);
}

void printfArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void) {
    int n ;
    do {
        printf("Nhap n :");
        scanf("%d", &n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nin mang 1 :\n");
    printfArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("\nmang 2 :\n");
    printfArray(arr, n);
    return 0;
}