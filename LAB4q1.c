#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void display();
void peek();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---");
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
                return 0;
            default:
                printf("\nInvalid choice!");
        }
    }
}

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("\nOverflow!");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("\nInserted: %d", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nUnderflow!");
    } else {
        printf("\nDeleted: %d", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nEmpty Queue");
    } else {
        printf("\nElements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1) {
        printf("\nEmpty Queue");
    } else {
        printf("\nFront: %d", queue[front]);
    }
}
