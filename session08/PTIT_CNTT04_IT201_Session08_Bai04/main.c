#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void) {
    int n ;
    do {
        printf("nhap n:");
        scanf("%d", &n);
    }while (n < 0);
    int arr[n];
    printf("\n nhap mang\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d" , &arr[i]);
    }
    printf("\n in mang 1:\n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("\n mang 2:\n");
    printArray(arr, n);
    return 0;
}