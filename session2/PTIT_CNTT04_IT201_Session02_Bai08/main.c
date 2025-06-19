#include <stdio.h>

int main(void) {
    int arr[100] , n ;
    do {
        printf("nhap do dai mang :");
        scanf("%d",&n);
    }while (n < 0 || n > 100);
    printf("nhap mang \n");
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n -1 ; i++) {
        int flag = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                flag=0;
                break;
            }
        }
        if (flag) {
            printf("%d ",arr[i]);
        }
    }
    printf("%d",arr[n-1]);
    return 0;
}