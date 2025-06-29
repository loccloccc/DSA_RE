#include <stdio.h>
void binary(int n) {
    if (n==0) return;
    binary(n/2);
    printf("%d",n%2);
}
int main(void) {
    int n;
    printf("nhap n : ");
    scanf("%d", &n);
    binary(n);
    return 0;
}