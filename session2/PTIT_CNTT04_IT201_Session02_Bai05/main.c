#include <stdio.h>

int main(void) {
    int arr[100];
    int n , index;
    do {
        printf("moi ban nhap do dai mang");
        scanf("%d",&n);
    }while (n<0 || n >100);
    arr[n];
    for (int i = 0; i < n; i++) {
        printf("gia tri thu %d " , i+1);
        scanf("%d",&arr[i]);
    }
    printf(" in 1 : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("moi ban nhap vi tri ban muon xoa :");
    scanf("%d",&index);
    if (index < 0 || index > n) {
        printf("vi tri xoa khong hop le ....");
        return;
    }
    for (int i = index ; i < n ; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf(" in 1 : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}