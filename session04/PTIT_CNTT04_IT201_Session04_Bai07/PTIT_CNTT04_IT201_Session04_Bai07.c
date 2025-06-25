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
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nin mang\n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    for (int i = 0 ; i < n/2 ; i++) {
        if (arr[i]==arr[n-1-i]) {
            printf("cac cap doi xung : (%d:%d)\n",arr[i],arr[n-1-i]);
        }
    }
    return 0;
}