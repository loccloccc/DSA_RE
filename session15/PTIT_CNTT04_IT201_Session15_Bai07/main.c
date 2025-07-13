#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quere {
    char (*name)[31];
    int fornt;
    int rear;
    int cap;
}Quere;

Quere *createQuere(int cap) {
    Quere *q = (Quere*)malloc(sizeof(Quere));
    q->fornt = 0 ;
    q->rear = -1 ;
    q->cap = cap ;
    q->name = (char(*)[31])malloc(cap * sizeof(char[31]));
    return q;
};

void enQuere(Quere *q, char name[]) {
    if (q->rear == q->cap - 1) return;
    q->rear = q->rear + 1;
    strcpy(q->name[q->rear], name);
}

void getQuere(Quere *q) {
    if (q->rear ==  - 1) {
        printf("Danh sach rong");
        return;
    };
    printf( "khach hang : %s " ,q->name[q->fornt]);
    q->fornt++;
}

void printQuere(Quere *q) {
    if (q->rear ==  - 1) {
        printf("Danh sach rong");
        return;
    };
    printf("danh sach khach dang cho \n");
    for (int i = q->fornt ; i < q->rear + 1; i++) {
        printf("%s", q->name[i]);
        printf("\n");
    }
}

void menu() {
    printf("Menuuu\n");
    printf("1. Them khach hang moi .\n");
    printf("2 . Phuc vu .\n");
    printf("3 . Danh sach khach cho.\n");
    printf("4 . Thoat.\n");
}
int main(void) {
    Quere *q = createQuere(100);
    char name[31];
    int choice;
    do {
        menu();
        printf("lua chon cua ban : ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("nhap ten khach hang : ") ;
                fgets(name, 31, stdin);
                name[strcspn(name,"\n")] = '\0';
                enQuere(q, name);
                printf("\n");
                break;
            case 2:
                getQuere(q);
                printf("\n");
                break;
            case 3:
                printQuere(q);
                printf("\n");
                break;
            case 4 :
                printf("thoat thanh cong");
                break;
            default:
                printf("khong co lua chon nay");
        }

    }while (choice != 4);
    return 0;
}