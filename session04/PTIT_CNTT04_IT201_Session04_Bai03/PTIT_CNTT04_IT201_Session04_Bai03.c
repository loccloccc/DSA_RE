#include <stdio.h>

int main(void) {
    int n ;
    do {
        printf("nhap do dai mang:");
        scanf("%d",&n);
    }while (n < 0);
    int arr[n];
    printf("nhap mang:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("arr[%d] = " , i);
        scanf("%d",&arr[i]);
    }
    printf("\n in mang \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }
    int min = arr[0] , minIndex = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex=i;
        }
    }
    printf("\n %d", minIndex);
    return 0;
}