#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* addNodes(Node* root, int data) {
    Node* p = createNode(data);
    if (root == NULL) {
        return p;
    }
    if (data < root->data) {
        root->left = addNodes(root->left, data);
    }else if (data > root->data) {
        root->right = addNodes(root->right, data);
    }
    return root;
}
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(void) {
    Node* root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    Node* node5 = createNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    int n ;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    root = addNodes(root, n);
    preOrder(root);
    return 0;
}