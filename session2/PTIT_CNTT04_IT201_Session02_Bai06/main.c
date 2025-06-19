#include <stdio.h>

int main(void) {
    // them vao vi tri chi dinh
    int arr[100] ;
    int n , index , value;
    do {
        printf("nhap do dai mang : ");
        scanf("%d",&n);
    }while (n < 0 || n > 100);
    arr[n];
    printf("nhap mang : \n");
    for (int i = 0 ; i < n ; i++) {
        printf("pha tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("in mang : \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("nhap vi tri ban muon them : ");
    scanf("%d",&index);
    if (index<0 || index>n) {
        printf("vi tri them khong hop le.");
        return;
    }
    printf("nhap gia tri muon them : ");
    scanf("%d",&value);
    for (int i = n ; i > index ; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    n++;
    printf("\n");
    printf("in mnag lan 2 : ");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}