#include <stdio.h>
#include <stdlib.h>

int average(int *arr , int n);
int main(void) {
    int n ;
    printf("nhap do dai mang : \t");
    scanf("%d",&n);
    if (n<=0) {
        printf("gia tri nhap khong hop le");
        return;
    }
    int *arrPtr = (int*) malloc(n * sizeof(int));
    if (arrPtr==NULL) {
        printf("loi");
        return;
    }
    printf("nhap mang\n");
    for (int i = 0; i < n ; i++) {
        printf("phan tu thu %d : \t " , i+1);
        scanf("%d",&arrPtr[i]);
    }
    printf("in mang:\n");
    for (int i = 0; i < n ; i++) {
        printf("%d ",arrPtr[i]);
    }
    printf("\n");
    int res = average(arrPtr , n);
    printf("ket qua =  %d" , res);
    free(arrPtr);
    return 0;
}
int average(int *arr , int n) {
    int sum = 0 ;
    int count = 0 ;
    for (int i = 0; i < n; i++) {
        if (arr[i]%2==0) {
            sum+=arr[i];
            count++;
        }
    }
    return sum/count;
}