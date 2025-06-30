#include <stdio.h>

void selectionSort(int arr[] , int size) {
    for (int i = 0 ; i < size -1 ; i++) {
        int minIndex = i;
        for (int j = i+1 ; j < size ; j++) {
            if (arr[minIndex] < arr[j]) {
                minIndex = j ;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int arr[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%d " , arr[i]);
    }
}
int main(void) {
    int n ;
    do {
        printf("nhap do dai mang : ");
        scanf("%d",&n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang : ");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n in lan 1 : \n");
    printArr(arr , n);
    selectionSort( arr,n);
    printf("\n in lan 2 \n");
    printArr(arr,n);
    return 0;
}