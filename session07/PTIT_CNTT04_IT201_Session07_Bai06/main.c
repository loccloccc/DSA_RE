#include <stdio.h>

void merge(int arr[] , int left , int middle , int right) {
    int len_left = middle - left + 1;
    int len_right = right - middle;
    int arr_left[len_left];
    int arr_right[len_right];
    for (int i = 0 ; i < len_left ; i++) {
        arr_left[i] = arr[left+i];
    }
    for (int i = 0 ; i < len_right ; i++) {
        arr_right[i] = arr[middle+i+1];
    }
    int i = 0, j = 0, k = left;
    while (i < len_left && j < len_right) {
        if (arr_left[i] <= arr_right[j]) {
            arr[k] = arr_left[i];
            i++;
        }
        else {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }
    while (i < len_left ) {
        arr[k] = arr_left[i];
        i++;
        k++;
    }
    while (j < len_right ) {
        arr[k] = arr_right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[] , int left , int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr , left , middle);
        mergeSort(arr , middle + 1, right);
        merge(arr , left , middle , right);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
int main(void) {
   int n ;
    do {
        printf("nhap do dai mang :");
        scanf("%d",&n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang :\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang :\n");
    printArray(arr, n);
    mergeSort(arr,0,n-1);
    printf("\n in mang 2:\n");
    printArray(arr,n);
    return 0;
}