#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n ;
    printf("nhap do dai mang : ");
    scanf("%d",&n);
    if (n==0) {
        printf("so luong phan tu phai lon hon 0");
        return 0;
    }else if (n<0) {
        printf("so luong phan tu khong duoc am");
        return 0;
    }
    int *arrPtr = (int*)malloc(n*sizeof(int));
    printf("nhap mang .\n");
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d : ", i+1);
        scanf("%d",&arrPtr[i]);
    }
    printf("in :\n");
    for (int i = 0; i < n; i++) {
        printf("so thu %d =  %d \n",i+1,arrPtr[i]);
    }
    free(arrPtr);
    return 0;
}
