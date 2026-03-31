#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int q1[SIZE], q2[SIZE];
int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;

void enqueue(int* q, int* f, int* r, int val) {
    if (*r == SIZE - 1) return;
    if (*f == -1) *f = 0;
    (*r)++;
    q[*r] = val;
}

int dequeue(int* q, int* f, int* r) {
    if (*f == -1 || *f > *r) return -1;
    int val = q[*f];
    (*f)++;
    if (*f > *r) *f = *r = -1;
    return val;
}

int isEmpty() {
    return (f1 == -1);
}

void push(int val) {
    enqueue(q2, &f2, &r2, val);

    while (f1 != -1) {
        enqueue(q2, &f2, &r2, dequeue(q1, &f1, &r1));
    }

    int* temp_q = q1; // Swapping names/pointers logic
    int temp_f = f1;
    int temp_r = r1;

    f1 = f2; r1 = r2;
    f2 = temp_f; r2 = temp_r;
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nPopped: %d", dequeue(q1, &f1, &r1));
}

void peek() {
    if (isEmpty()) {
        printf("\nStack is empty!");
    } else {
        printf("\nTop element: %d", q1[f1]);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty!");
    } else {
        printf("\nStack elements: ");
        for (int i = f1; i <= r1; i++) {
            printf("%d ", q1[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Stack using 2 Queues ---");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) printf("\nStack is empty.");
                else printf("\nStack is not empty.");
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}
