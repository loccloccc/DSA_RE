#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;
typedef struct TaskList {
    Task *tasks;
    struct TaskList *next;
}TaskList;
TaskList* createTask(Task* task) {
    TaskList *head = (TaskList*)malloc(sizeof(TaskList));
    head->tasks = task;
    head->next = NULL;
    return head;
}
typedef struct TaskDouleList {
    Task *tasks;
    struct TaskDouleList *next;
    struct TaskDouleList *prev;
}TaskDouleList;
TaskDouleList* createTaskDoule(Task* task) {
    TaskDouleList *head = (TaskDouleList*)malloc(sizeof(TaskDouleList));
    head->tasks = task;
    head->next = NULL;
    head->prev = NULL;
    return head;
}
TaskList* createTaskList() {}
// them
TaskList* addTask(TaskList *head , Task* t) {
    TaskList* newTask = createTask(t);
    if (head == NULL) {
        head = newTask;
        return head;
    }
    TaskList* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTask;
    return head;

}
int idF = 0;
TaskList *head = NULL;
TaskDouleList *headDoule = NULL;
TaskDouleList* addTaskDoule(TaskDouleList *head, Task* t) {
    TaskDouleList *newTask = createTaskDoule(t);
    if (head == NULL) {
        head = newTask;
        return head;
    }
    TaskDouleList* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTask;
    return head;
}
void inputTask() {
    Task* task = (Task*)malloc(sizeof(Task));
    idF++;
    task->id = idF;
    printf("id : %d\n",idF);
    getchar();
    printf("nhap tieu de nhiem vu : ");
    fgets(task->title, 100, stdin);
    task->title[strcspn(task->title,"\n")] = '\0';
    printf("nhap muc do uu tien cua nhiem vu : ");
    scanf("%d",&task->priority);
    getchar();
    printf("nhap thoi gian hoan thanh nhiem vu :");
    fgets(task->deadline, 100 , stdin);
    task->deadline[strcspn(task->deadline,"\n")] = '\0';
    head = addTask(head, task);
    printf("them thanh cong ...\n");
}
//hien thi
void displayTask() {
    if (head == NULL) {
        printf("danh sach nhiem vu dang lam rong .\n");
    }else {
        printf("Danh sach nhiem vu dang lam :\n");
        TaskList* current = head;
        while (current!=NULL) {
            printf("id : %d\n" , current->tasks->id);
            printf("title : %s\n" , current->tasks->title);
            printf("priority : %d\n" , current->tasks->priority);
            printf("deadline : %s\n" , current->tasks->deadline);
            printf("\n");
            current = current->next;
        }
    }
    printf("============================================\n");
    if (headDoule == NULL) {
        printf("danh sach nhiem vu da hoan thanh rong .\n");
    }else {
        TaskDouleList* current = headDoule;
        while (current!=NULL) {
            printf("id : %d\n" , current->tasks->id);
            printf("title : %s\n" , current->tasks->title);
            printf("priority : %d\n" , current->tasks->priority);
            printf("deadline : %s\n" , current->tasks->deadline);
            printf("\n");
            current = current->next;
        }
    }
}
// xoa
TaskList* deleteTast(int id) {
    if (id <= 0 ) {
        printf("id khong hop le ...\n");
        return NULL;
    }
    if (head->tasks->id == id) {
        TaskList* current = head;
        head = head->next;
        headDoule = addTaskDoule(headDoule,current->tasks);
        free(current);
        return head;
    }
    TaskList* current = head;
    while (current->next != NULL && current->next->tasks->id != id) current = current->next;
    if (current == head) {
        head = head->next;
        free(current);
    }
    TaskList* temp = current->next;
    headDoule = addTaskDoule(headDoule,temp->tasks);
    current->next = temp->next;
    free(temp);
    return head;
}
//cap nhat
void update(TaskList *head) {
    if (head==NULL) {
        printf("danh sach rong .\n");
        return;
    }
    int id ;
    printf("nhap id muon cap nhap : ");
    scanf("%d",&id);
    getchar();
    TaskList* current = head;
    while (current!=NULL && current->tasks->id != id) current = current->next;
    if (current == NULL) {
        printf("khong tim thay id");
        return;
    }
    printf("update...\n");
    printf("id : %d \n" , current->tasks->id);
    printf("nhap ten : ");
    fgets(current->tasks->title,100,stdin);
    current->tasks->title[strcspn(current->tasks->title,"\n")] = '\0';
    printf("nhap muc do uu tien : ");
    scanf("%d",&current->tasks->priority);
    getchar();
    printf("nhap thoi gian hoan thanh nhiem vu : ");
    fgets(current->tasks->deadline,100,stdin);
    current->tasks->deadline[strcspn(current->tasks->deadline,"\n")] = '\0';
    head = addTask(head, current->tasks);
    printf("cap nhap thanh cong ...\n");
}
// danh dau nhiem vu da hoan thanh
void addCompelete() {
    int id ;
    printf("nhap id nhiem vu ban da hoan thanh : ");
    scanf("%d",&id);
    getchar();
    deleteTast(id);
    printf("them thanh cong ..\n");
}
//Sap xep nhiem vu
void sortTask() {
    if (head == NULL) {
        printf("danh sach rong .\n");
        return;
    }
    int swap;
    TaskList* current = head;
    Task* temp;
    do {
        swap = 0;
        while (current->next!=NULL) {
            if (current->tasks->priority > current->next->tasks->priority) {
                temp = current->tasks;
                current->tasks = current->next->tasks;
                current->next->tasks = temp;
                swap = 1;
            }
            current = current->next;
        }
    }while (swap);
    printf("sap sep thanh cong ..\n");
}
//Tim kiem nhiem vu
void searchTask() {
    if (head == NULL) {
        printf("danh sach rong .\n");
        return;
    }
    getchar();
    char name[100];
    printf("nhap ten ban muon tim kiem : ");
    fgets(name,100,stdin);
    name[strcspn(name,"\n")] = '\0';
    TaskList* current = head;
    int flag = 0;
    while (current!=NULL) {
        if (strstr(name,current->tasks->title) != NULL) {
            printf("id : %d \n",current->tasks->id);
            printf("title : %s \n",current->tasks->title);
            printf("priority : %d \n",current->tasks->priority);
            printf("deadline : %s\n",current->tasks->deadline);
            flag = 1;
            printf("\n");
        }
        current = current->next;
    }
    if (flag == 0) {
        printf("khong tim duoc ten : %s .\n",name);
    }
}



void menu() {
    printf("\n");
    printf("==========================================\n");
    printf("1 . Them moi nhiem vu .\n");
    printf("2 . Hien thi nhiem vu .\n");
    printf("3 . Xoa nhiem vu .\n");
    printf("4 . Cap nhat nhiem vu . \n");
    printf("5 . Nhiem vu da hoan thanh .\n");
    printf("6 . Sap xep nhiem vu . \n");
    printf("7 . Tim kiem nhiem vu .\n");
    printf("8 . Thoat chuong trinh . \n");
    printf("==========================================\n");
}
int main(void) {
    int choice;
    do {
        menu();
        printf("lua chon cua ban : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputTask();
                printf("....");
                break;
            case 2:
                displayTask();
                printf("....");
                break;
            case 3:
                int id;
                printf("nhap id ban muon xoa : ");
                scanf("%d", &id);
                head = deleteTast(id);
                printf("xoa thanh cong.\n");
                printf("....");
                break;
            case 4:
                update(head);
                printf("....");
                break;
            case 5:
                addCompelete();
                printf("....");
                break;
            case 6:
                sortTask();
                printf("....");
                break;
            case 7:
                searchTask();
                printf("....");
                break;
            case 8:
                printf("Thoat thanh cong!!!!!");
                break;
            default:
                printf("khong co lua chon nay !!!!!");
        }
    }while (choice != 8);
    return 0;
}