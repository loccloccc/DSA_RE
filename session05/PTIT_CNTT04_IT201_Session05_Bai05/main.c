#include <stdio.h>
#include <string.h>

int doiXung(char c[] , int start , int end) {
    if (start>=end) return 1;
    if (c[start]!=c[end]) return 0;
    return doiXung(c , start+1 , end-1);
}
int main(void) {
    char input[1000];
    printf("nhap chuoi: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int size = strlen(input);
    int res = doiXung(input , 0 , size-1);
    if (res==0) {
        printf("NO");
    }else {
        printf("YES");
    }
    return 0;
}