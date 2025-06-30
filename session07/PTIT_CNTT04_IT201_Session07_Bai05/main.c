#include <stdio.h>

void swap(int arr[] , int a , int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[] , int low , int high) {
    int pivot = arr[low];
    int count = 0 ;
    for (int i = low+1; i <= high; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }
    int indexPivot = low + count;
    swap(arr,low,indexPivot);
    int i = low;
    int j = high;
    while (i<indexPivot && j > indexPivot) {
        while (arr[i]<pivot) {
            i++;
        }
        while (arr[j]>pivot) {
            j--;
        }
        if (i < indexPivot && j > indexPivot) {
            swap(arr,i,j);
        }
    }
    return indexPivot;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(arr,low,high);
    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);
}
int main(void) {
    int n;
    do {
        printf("Please enter a number:\n");
        scanf("%d", &n);
    }while (n < 0);
    int arr[n];
    printf("\nnhap mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] : " , i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang\n");
    for (int i = 0 ; i < n ; i++) {
        printf(" %d  " , arr[i]);
    }
    //
    quickSort(arr, 0 , n-1);
    printf("\n in mang 2: \n");
    for (int i = 0 ; i < n ; i++) {
        printf(" %d " , arr[i]);
    }
    return 0;
}