#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* crereatNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int len(Node* head){
    Node* node = head;
    int lenght = 0;
    while(node!=NULL){
        lenght++;
        node = node->next;
    }
    return lenght;
}
Node* delFirst(Node* head){
    //B1 : ktra xem dslk co rong k , neu co tra ve null
    if(head==NULL) return NULL;
    //B2 : luu tru node dau tien hien tai vao 1 bien temp
    Node* temp = head;
    //B3 : di chuyen em sang node ke tiep
    head = head->next;
    //B4 Tien hanh xoa node dang duoc luu tru trong temp
    free(temp);
    //B5 tra ve node head moi tuong ung
    // xoa bo phan tu dau tien
    return head;
}

//xoa bo cuoi
Node* delLast(Node* head){
    // B1: Kiểm tra danh sách rỗng
    if (head == NULL) return NULL;

    // B2: Nếu chỉ có một phần tử
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // B3: Duyệt đến node kế cuối
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // B4: Xoá node cuối
    Node* xoaNode = current->next;
    current->next = NULL;
    free(xoaNode);

    // B5: Trả về danh sách đã cập nhật
    return head;
}

//xoa vi tri bat ki

Node* delAtindex(Node* head , int index){
    //b1 : kiem tra index co hop le khong
    if(index < 0 || index > len(head)) return head;
    //b2: ktra index = 0
    if(index == 0) return delFirst(head);
    //b3 : ktra index = len -1
    if(index == len(head) -1) return delLast(head);
    //b4: duyet den node ke can voi node can xoa
    Node* current = head;
    for(int i = 0 ; i < index - 1 ; i++){
        current = current->next;
    }
    //b5 : lay thong tin node can xoa va luu no
    Node* xoaNode = current->next;
    Node* next = xoaNode->next;
    //b6 : ngat ket noi node ke can voi node can xoa
    // b7 : tro lai vi tri cua node ke can
    current->next = next;
    //b8 : xoa node can xoa do
    free(xoaNode);
    return head;
}

void print(Node* head) {
    Node* node = head;
    while (node!=NULL) {
        printf("%d -> " ,node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main(void) {
    Node* head = NULL;
    Node* node1 = crereatNode(1);
    Node* node2 = crereatNode(2);
    Node* node3 = crereatNode(3);
    Node* node4 = crereatNode(4);
    Node* node5 = crereatNode(5);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int index ;
    printf("nhap vi tri muon xoa :");
    scanf("%d",&index);
    head = delAtindex(head , index-1);
    print(head);
    return 0;
}