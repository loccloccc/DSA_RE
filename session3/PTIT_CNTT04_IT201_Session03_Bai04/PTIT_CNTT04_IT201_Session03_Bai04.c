#include <stdio.h>
#include <stdlib.h>

int maxNumber( int row , int col , int arr[row][col]);
int minNumber( int row , int col , int arr[row][col]);
int main(void) {
    int row, col;
    printf("nhap hang:");
    scanf("%d", &row);
    printf("nhap cot:");
    scanf("%d", &col);
    if (row<=0 || col<=0) {
        printf("loi\n");
        return 0;
    }
    if (row > 1000 || col > 1000) {
        printf("loi\n");
        return 0;
    }
    int arr[row][col];
    printf("nhap mang:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("in \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n \n");
    int max = maxNumber( row, col ,arr);
    int min = minNumber( row, col , arr);
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    return 0;
}

int maxNumber( int row , int col  , int arr[row][col]) {
    int max = arr[0][0];
    for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col ; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int minNumber( int row , int col , int arr[row][col]) {
    int min = arr[0][0];
    for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col ; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}