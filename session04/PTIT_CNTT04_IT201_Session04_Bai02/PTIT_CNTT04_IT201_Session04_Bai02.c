#include <stdio.h>

int main(void) {
    int n ;
    do {
        printf("nhap do dai mang :");
        scanf("%d",&n);
    }while (n < 0);

    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d]: ", i);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("in mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int max = arr[0] , maxIndex = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i]>max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    printf("%d", maxIndex);
    return 0;
}