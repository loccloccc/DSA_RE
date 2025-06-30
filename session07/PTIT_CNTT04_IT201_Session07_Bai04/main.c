#include <stdio.h>
#include <string.h>

void printString(char str[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%c ",str[i]);
    }
}

void sortStr(char str[] , int size) {
    for (int i = 0 ; i < size -1 ; i++) {
        for (int j = 0 ; j < size -1 -i ; j++) {
            if (str[j]>str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}
int main(void) {
    char str[100];
    printf("moi nhap chuoi :");
    fgets(str,sizeof(str)/sizeof(str[0]),stdin);
    if ((strcspn(str, "\n")) == strlen(str)) {
        while ((getchar())!='\n');
    } else {
        str[strcspn(str, "\n")] = '\0';
    }
    int size  = strlen(str);
    printf("\nin lan 1 : \n");
    printString(str,size);
    sortStr(str,size);
    printf("\nin lan 2 : \n");
    printString(str,size);
    return 0;
}