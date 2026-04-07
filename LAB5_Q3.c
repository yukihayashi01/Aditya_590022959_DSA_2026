
/*
Tree will traverse in this order 

				  [1]
				 /   \
                /     \
              [2]     [3]
              / \     / \
             /   \   /   \
            [4] [5] [6] [7]
*/


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
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);       
    printf("%d ", root->data);          
    inorderTraversal(root->right);     
}


void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);          
    preorderTraversal(root->left);      
    preorderTraversal(root->right);     
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    
    postorderTraversal(root->left);     
    postorderTraversal(root->right);    
    printf("%d ", root->data);         
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    
    printf("1. Inorder Traversal   : ");
    inorderTraversal(root);
    printf("\n");

    printf("2. Preorder Traversal  : ");
    preorderTraversal(root);
    printf("\n");

    printf("3. Postorder Traversal : ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
