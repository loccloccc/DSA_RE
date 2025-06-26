#include <stdio.h>

void in(int n);


int main(void) {
    int n ;
    printf("nhap n : ");
    scanf("%d",&n);
    in(n);
    return 0;
}
void in(int n) {
    if (n==1 ) {
        printf("%d\n",n);
        return;
    }
    in(n-1);
    printf("%d\n",n);
}
