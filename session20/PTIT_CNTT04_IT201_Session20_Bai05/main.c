#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMaxValue(Node* root) {
    if (root == NULL) {
        return -9999999;
    }
    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);
    int max = root->data;
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    return max;
}


int main(void) {
    Node* root = NULL;
    root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    printf("The max value is: %d\n", findMaxValue(root));
    return 0;
}