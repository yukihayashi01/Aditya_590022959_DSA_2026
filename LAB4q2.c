#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value);
void dequeue();
void display();
void peek();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue using Linked List ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
}

void enqueue(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed!");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInserted: %d", value);
}
void dequeue() {
    if (front == NULL) {
        printf("\nUnderflow!");
        return;
    }
    struct node* temp = front;
    printf("\nDeleted: %d", front->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("\nEmpty Queue");
    } else {
        struct node* temp = front;
        printf("\nElements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void peek() {
    if (front == NULL) {
        printf("\nEmpty Queue");
    } else {
        printf("\nFront: %d", front->data);
    }
}


