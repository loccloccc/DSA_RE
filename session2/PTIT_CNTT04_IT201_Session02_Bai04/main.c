#include <stdio.h>

int main(void) {
    int arr[100];
    int n , index , value;
    do {
        printf("moi ban nhap do dai mang : ");
        scanf("%d",&n);
    }while (n<0 || n > 100);
    arr[n];
    printf("nhap lan luot gia tri cac phan tu : \n");
    for (int i = 0 ; i < n ; i++) {
        printf("phan tu thu [%d] la:" , i+1);
        scanf("%d",&arr[i]);
    }
    printf("in 1 : \t");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    printf("moi ban nhap vi tri muon sua : ");
    scanf("%d",&index);
    printf("moi ban nhap gia tri : ");
    scanf("%d",&value);
    arr[index] = value;
    printf("in 1 : \t");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}