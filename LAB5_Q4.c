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

#define MAX_Q_SIZE 500

struct Node** createQueue(int* front, int* rear) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}

void enqueue(struct Node** queue, int* rear, struct Node* newNode) {
    if (*rear == MAX_Q_SIZE) {
        printf("Queue Overflow\n");
        return;
    }
    queue[*rear] = newNode;
    (*rear)++;
}

struct Node* dequeue(struct Node** queue, int* front) {
    (*front)++;
    return queue[*front - 1];
}

int isQueueEmpty(int front, int rear) {
    return front == rear;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    int front, rear;
    struct Node** queue = createQueue(&front, &rear);

    enqueue(queue, &rear, root);

    while (!isQueueEmpty(front, rear)) {
        struct Node* current = dequeue(queue, &front);
        
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(queue, &rear, current->left);
        }

        if (current->right != NULL) {
            enqueue(queue, &rear, current->right);
        }
    }
    
    free(queue); 
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
