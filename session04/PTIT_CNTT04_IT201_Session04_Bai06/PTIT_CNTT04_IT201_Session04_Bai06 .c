#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};
typedef struct Student Student;
int main(void) {
    int n ;
    do {
        printf("nhap do dai mang:");
        scanf("%d",&n);
    }while (n<0);
    Student student[n];
    printf("nhap thong tin:\n");
    for (int i = 0 ; i < n ; i++) {
        printf("nhap id : ");
        scanf("%d",&student[i].id);
        getchar();
        printf("nhap ten:");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        size_t len = strlen(student[i].name);
        if (student[i].name[len - 1] == '\n') {
            student[i].name[len - 1] = '\0';
        }
        printf("nhap tuoi:");
        scanf("%d",&student[i].age);
    }
    printf("\n in \n");
    for (int i = 0 ; i < n ; i++) {
        printf("id : %d , ten : %s , tuoi: %d \n " , student[i].id , student[i].name , student[i].age);
    }
    int id;
    printf("nhap id muon tim:");
    scanf("%d",&id);
    for (int i = 0 ; i < n ; i++) {
        if (student[i].id == id) {
            printf("id : %d , ten : %s , tuoi: %d \n " , student[i].id , student[i].name , student[i].age);
            break;
        }
    }
    return 0;
}