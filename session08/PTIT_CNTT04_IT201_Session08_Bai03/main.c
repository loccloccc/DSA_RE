#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
}
int main(void) {
    int n ;
    do {
        printf("nhap n :");
        scanf("%d", &n);
    }while (n < 0);
    int arr[n];
    printf("\nnhap mang :\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]:", i+1);
        scanf("%d",&arr[i]);
    }
    printf("in lan 1 :");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("in lan 2 :");
    printArray(arr, n);


    return 0;
}