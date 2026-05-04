#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int tree[MAX];

void initTree() {
    for (int i = 1; i < MAX; i++) {
        tree[i] = -1;
    }
}

void insert(int val) {
    for (int i = 1; i < MAX; i++) {
        if (tree[i] == -1) {
            tree[i] = val;
            printf("Success: Inserted %d at index %d.\n", val, i);
            return;
        }
    }
    printf("Error: Tree is full!\n");
}

void displayTree() {
    int isEmpty = 1;
    printf("\nTree array representation (starting at index 1): ");
    for (int i = 1; i < MAX; i++) {
        if (tree[i] != -1) {
            printf("[%d]:%d ", i, tree[i]);
            isEmpty = 0;
        }
    }
    if (isEmpty) {
        printf("(Tree is empty)");
    }
    printf("\n");
}

void displayNodeInfo(int val) {
    int index = -1;
    
    for (int i = 1; i < MAX; i++) {
        if (tree[i] == val) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nNode %d not found in the tree.\n", val);
        return;
    }

    printf("\n--- Relationships for Node %d (Index %d) ---\n", val, index);

    if (index == 1) {
        printf("Parent      : None (This is the Root node)\n");
    } else {
        int parentIndex = index / 2;
        printf("Parent      : %d (at index %d)\n", tree[parentIndex], parentIndex);
    }

    int leftIndex = 2 * index;
    if (leftIndex < MAX && tree[leftIndex] != -1) {
        printf("Left Child  : %d (at index %d)\n", tree[leftIndex], leftIndex);
    } else {
        printf("Left Child  : None\n");
    }

    int rightIndex = (2 * index) + 1;
    if (rightIndex < MAX && tree[rightIndex] != -1) {
        printf("Right Child : %d (at index %d)\n", tree[rightIndex], rightIndex);
    } else {
        printf("Right Child : None\n");
    }
    printf("-----------------------------------------\n");
}

int main() {
    int choice, val;
    initTree();

    while (1) {
        printf("1. Insert Element\n");
        printf("2. Display Tree Elements\n");
        printf("3. Find Parent and Children of a Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                displayTree();
                break;
            case 3:
                printf("Enter node value to search: ");
                scanf("%d", &val);
                displayNodeInfo(val);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
