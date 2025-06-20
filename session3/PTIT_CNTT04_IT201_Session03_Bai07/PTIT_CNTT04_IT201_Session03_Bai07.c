#include <stdio.h>


int sum(int row , int col , int arr[row][col]);
int main(void) {
    int row , col ;
    printf("nhap hang:");
    scanf("%d" , &row);
    printf("nhap cot:");
    scanf("%d" , &col);
    if (row <0 || col <0) {
        printf("loi\n");
    }
    if (row > 1000 || col > 1000) {
        printf("loi\n");
    }
    int arr[row][col];
    printf("nhap mang\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = " , i, j);
            scanf("%d" , &arr[i][j]);
        }
    }
    printf("in \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int res = sum(row, col, arr);
    printf("%d\n", res);
    return 0;
}
int sum(int row , int col , int arr[row][col]) {
    int res = 0 ;
    int k;
    printf("nhap hang muon tinh tong:");
    scanf("%d" , &k);
    if (k > 0 && k < row) {
        for (int i = 0; i < row; i++) {
            if (i+1 == k) {
                for (int j = 0; j < col; j++) {
                    res += arr[i][j];
                }
            }
        }
    }else {
        printf("hang can tinh khong ton tai");
        return;
    }
    return res;
}