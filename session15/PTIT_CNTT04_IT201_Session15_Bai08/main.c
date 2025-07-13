#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QuereOld {
    char (*name)[50];
    int fount;
    int rear;
    int cap;
}QuereOld;
typedef struct QuereNew {
    char (*name)[50];
    int fount;
    int rear;
    int cap;
}QuereNew;
QuereNew *createQuereNew(int cap) {
    QuereNew *q = (QuereNew *)malloc(sizeof(QuereNew));
    q->cap = cap;
    q->fount = 0;
    q->rear = -1;
    q->name = (char(*)[50])malloc(q->cap * sizeof(char[50]));
    return q;
}
QuereNew *createQuereOld(int cap) {
    QuereNew *q = (QuereNew *)malloc(sizeof(QuereNew));
    q->cap = cap;
    q->fount = 0;
    q->rear = -1;
    q->name = (char(*)[50])malloc(q->cap * sizeof(char[50]));
    return q;
}

void enQuereOld(QuereOld *q , char name[]) {
    if (q->rear == q->cap -1) {
        printf("danh sach day");
        return;
    }
    q->rear = q->rear + 1;
    strcpy(q->name[q->rear], name);
}
void enQuereNew(QuereNew *q, char name[]) {
    if (q->rear == q->cap -1) {
        printf("danh sach day");
        return;
    }
    q->rear = q->rear + 1;
    strcpy(q->name[q->rear], name);
}

void getQuere(QuereOld *qOld, QuereOld *qNew) {
    if (qOld->fount <=  qOld->rear) {
        printf("khach hang tren 60 tuoi : %s " , qOld->name[qOld->fount]);
        qOld->fount = qOld->fount + 1;
    }else if (qNew->fount <= qNew->rear) {
        printf("khach hang duoi 60 tuoi : %s " ,qNew->name[qNew->fount]);
        qNew->fount = qNew->fount + 1;
    }
    else {
        printf("Danh sach rong\n");
    }
}


void menu() {
    printf("Menuuu\n");
    printf("1.Nhap thong tin khach hang\n");
    printf("2.phuc vu khach hang\n");
    printf("3.Thoat.\n");
}

int main(void) {
    QuereOld *qOld = createQuereOld(100);
    QuereNew *qNew = createQuereNew(100);
    int choice ;
    char name[31] ;
    int age;

    do {
        menu();
        printf("lua chon cua ban : ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap thong tin khach hang\n");
                printf("Nhap ten : ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name,"\n")] = '\0';
                printf("nhap tuoi : ");
                scanf("%d", &age);
                getchar();
                if (age>= 60) enQuereOld(qOld,name);
                else enQuereNew(qNew,name);
                printf("\n");
                break;
            case 2:
                getQuere(qOld,qNew);
                printf("\n");
                break;
            case 3:
                printf("thoat thanh cong");
                break;
            default:
                printf("khong co lua chon nay");
        }
    }while (choice!=3);
    return 0;
}