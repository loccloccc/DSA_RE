#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int check(Node* node  , int value) {
   if (node == NULL) {
       return 0;
   }
    if (node->data == value) {
        return 1;
    }
    return check(node->left, value) || check(node->right, value);
}


int main(void) {
    Node* root = NULL;
    root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    int n ;
    printf("nhap gia tri : ");
    scanf("%d", &n);
    if (check(root, n)) {
        printf("TRUE");
    }else {
        printf("FASLE");
    }

    return 0;
}