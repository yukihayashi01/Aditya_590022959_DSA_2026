#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree() {
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = createNode(data);

    printf("Enter the left child of %d (Enter -1 for no child): ", data);
    newNode->left = buildTree();

    printf("Enter the right child of %d (Enter -1 for no child): ", data);
    newNode->right = buildTree();

    return newNode;
}

int countTotalNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0; 
    }
    
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    struct Node* root = NULL;

    printf("===== Binary Tree Creation =====\n");
    printf("Enter the data for the Root node (Enter -1 for empty tree): ");
    root = buildTree();

    printf("\n===== Tree Statistics =====\n");
    if (root == NULL) {
        printf("The tree is completely empty.\n");
    } else {
        printf("Total number of nodes : %d\n", countTotalNodes(root));
        printf("Number of leaf nodes  : %d\n", countLeafNodes(root));
        printf("Height of the tree    : %d\n", calculateHeight(root));
    }

    return 0;
}
