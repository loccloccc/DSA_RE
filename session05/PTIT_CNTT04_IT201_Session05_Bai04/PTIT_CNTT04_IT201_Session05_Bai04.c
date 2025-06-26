#include <stdio.h>
int sumRecursion(int num1 , int num2) {
    if (num2 <  num1 || num2 <= 0 || num1 <= 0) {
        return 0;
    }
    int sum = 0 ;
    sum = num2 + sumRecursion(num1,num2-1);
    return sum;
}
int main(void) {
    int numb1 , numb2;
    printf("Enter the first number : ");
    scanf("%d", &numb1);
    printf("Enter the second number : ");
    scanf("%d", &numb2);
    int res2 = sumRecursion(numb1,numb2);
    if (res2 == 0) {
        printf("khong hop le");
        return;
    }else {
        printf("%d\n", res2);
    }

    return 0;
}