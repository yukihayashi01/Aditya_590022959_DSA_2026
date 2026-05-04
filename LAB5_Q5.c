/*
Tree Used here 

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

#define MAX_STACK_SIZE 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* stack[MAX_STACK_SIZE];
int top = -1;

void push(struct Node* node) {
    if (top >= MAX_STACK_SIZE - 1) {
        return;
    }
    stack[++top] = node;
}

struct Node* pop() {
    if (top < 0) {
        return NULL;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void preorderIterative(struct Node* root) {
    if (root == NULL) {
        return;
    }

    top = -1; 
    push(root);

    while (!isEmpty()) {
        struct Node* current = pop();
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(current->right);
        }
        if (current->left != NULL) {
            push(current->left);
        }
    }
}

void inorderIterative(struct Node* root) {
    if (root == NULL) {
        return;
    }

    top = -1; 
    struct Node* current = root;

    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorderIterative(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderIterative(root);
    printf("\n");

    return 0;
}

