#include <stdio.h>

int main(void) {
    // nhap mang va tim tong gia tri bang gia tri cho truoc
    int arr[100];
    int n , sum , check = 0 , numb1 , numb2;
    do {
        printf("nhap do dai mang :");
        scanf("%d", &n);
    }while (n < 0 || n > 100);
    arr[n];
    printf("nhap mang .\n");
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d " , i + 1);
        scanf("%d", &arr[i]);
    }
    printf("in mang : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("nhap tong: ");
    scanf("%d", &sum);
    for (int i = 0; i < n; i++) {
        for (int j = i+1 ; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                check++;
                numb1=arr[i];
                numb2 = arr[j];
            }
        }
    }
    if (check!=0) {
        printf("%d va %d  \n", numb1, numb2);
    }else {
        printf("khong tim thay");
    }
    return 0;
}