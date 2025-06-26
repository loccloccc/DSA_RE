#include <stdio.h>
//chua bai 9 ss4
int binarySearchint(int arr[] , int low , int high , int key) {
    // điều kiện rừng khi không tìm thấy
    if (low>high) {
        return -1;
    }
    // dk rừng khi tìm thấy
    int mid = (low+high)/2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] > key) {
        return binarySearchint(arr,low,mid-1,key);
    }
    return binarySearchint(arr,mid+1,high,key);
}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}