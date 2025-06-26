#include <stdio.h>

int sum(int n);
int main(void) {
    int n ;
    printf("nhap n :");
    scanf("%d",&n);
    int res = sum(n);
    printf("ket qua = %d",res);
    return 0;
}
int sum(int n) {
    if (n==0) return 0;
    return n + sum(n-1);
}