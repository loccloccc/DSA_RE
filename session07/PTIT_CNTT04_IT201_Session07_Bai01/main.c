#include <stdio.h>


void bubbleSort(int arr[] , int size) {
    for (int i = 0 ; i < size -1 ; i++) {
        for (int j = 0 ; j < size - i -1 ; j++) {
            if (arr[i]>arr[j+1]) {
                int temp = arr[i];
                arr[i]  = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }
}
//hàm in
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
    printf("\n nhap mang : \n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] " , i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n in mang lan 1 : \n");
    printArr(arr,n);
    bubbleSort(arr,n);
    printf("\n in mang da sap xep:\n");
    printArr(arr,n);
    return 0;
}