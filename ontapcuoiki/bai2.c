//
// Created by loc on 25/07/2025.
//
#include<stdio.h>
#include<stdlib.h>


typedef struct Data {

};



void menu() {
    printf("\n");
    printf("============================\n");
    printf("1 . INSERT\n");
    printf("2 . UNDO\n");
    printf("3 . REDO .\n");
    printf("4 . Hien thi .\n");
    printf("5 . thoat .\n");
    printf("==============================\n");
}
int main() {
    int choice;
    do {
        menu();
        printf("nhap lua chon : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("thoat chuong trinh.\n");
                break;
            default:
                printf("khong co lua chon nay .\n");
        }
    }while (choice != 5);
    return 0;
}