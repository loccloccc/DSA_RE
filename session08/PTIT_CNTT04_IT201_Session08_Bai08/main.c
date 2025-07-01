#include <stdio.h>
void insertionSort(int arr[] , int n) {
    for (int i = 0 ; i < n ; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int binarySearch(int arr[] , int n , int value) {
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == value) {
            return i + 1;
        }
    }
    return -1;
}

int linearSearch(int arr[] , int n , int value) {
    int left = 0;
    int right = n -1;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == value){
            return mid + 1;
        }else if(arr[mid] < value){
            left = mid + 1;
        }else if(arr[mid] > value){
            right = mid - 1;
        }
    }
}

void printArray(int arr[] , int n) {
    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void) {
        int n ;
        do{
            printf("nhap n:");
            scanf("%d", &n);
        }while(n < 0);
        int arr[n];
    printf("nhap mang:\n");
    for(int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nin mang chua sap xep\n");
    printArray(arr , n);
    insertionSort(arr , n);
    printf("\n in manh sau khi sap xep:\n");
    printArray(arr , n);
    int value ;
    printf("nhap gia tri can tim:");
    scanf("%d", &value);
    int res = binarySearch(arr , n , value);
    if(res == -1) {
        printf("gia tri khong co trong mang...");
    }else {
        printf("vi tri thu %d .",res);
    }
        return 0;
}