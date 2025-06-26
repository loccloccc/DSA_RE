#include <stdio.h>

int resMultiply(int n);
int main(void) {
    int n;
    printf("nhap n :");
    scanf("%d",&n);
    int res = resMultiply(n);
    if (res==-1) {
        printf("khong hop le");
    }else if (res == 0) {
        printf("ket qua = %d",res);
    }else {
        printf("ket qua = %d",res);
    }
    return 0;
}

int resMultiply(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) return 1;
    return n*resMultiply(n-1);
}