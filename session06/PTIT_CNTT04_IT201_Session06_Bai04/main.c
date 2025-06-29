#include <stdio.h>

int maxNumber( int size , int arr[]) {
    if (size==0) return 0;
    if (size == 1 ) return arr[0];

    if (arr[size-1] > maxNumber(size-1 , arr)) return arr[size-1];
    else return maxNumber(size -1 , arr);

}

int minNumber(int size , int arr[]) {
    if (size==0) return 0;
    if (size == 1) return arr[0];
    if (arr[size-1] < minNumber(size-1,arr)) return arr[size-1];
    else return minNumber(size -1 , arr);
}
int main(void) {
    int size ;
    do {
        printf("nhap do dai mang:");
        scanf("%d", &size);
    }while (size<0);
    int arr[size];
    printf("nhap mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = " , i);
        scanf("%d", &arr[i]);
    }
    printf("\nin mnag\n");
    for (int i = 0 ; i < size; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    int max = maxNumber(size , arr);
    int min = minNumber(size , arr);
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    return 0;
}