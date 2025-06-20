#include <stdio.h>

int diagonalMain(int row , int col , int arr[row][col]);
int diagonalSub(int row , int col , int arr[row][col]);
int main(void) {
    int row , col ;
    printf("nhap hang :");
    scanf("%d", &row);
    printf("nhap cot:");
    scanf("%d", &col);
    printf("nhap mang\n");
    if (row <= 0 || col <= 0) {
        printf("loi");
        return;
    }
    if (row!=col) {
        printf("khong ton tai duong cheo chinh , duong cheo phu");
        return;
    }
    int arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("in\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    int sumMain = diagonalMain(row , col , arr);
    int sumSub = diagonalSub(row , col , arr) ;
    printf("main = %d " , sumMain);

    printf("sub = %d " , sumSub);
    return 0;
}
int diagonalMain(int row , int col , int arr[row][col]) {
    int sum = 0 ;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i==j) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}
int diagonalSub(int row , int col , int arr[row][col]) {
    int sum = 0 ;
    for (int i = 0 ; i < row; i++) {
        for (int j = 0  ; j < col; j++) {
            if (i+j==row-1) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}