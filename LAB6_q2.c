#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void initHeap(MinHeap* h) {
    h->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap* h, int val) {
    if (h->size == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    int i = h->size;
    h->arr[i] = val;
    h->size++;
    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteRoot(MinHeap* h) {
    if (h->size <= 0) {
        printf("Heap Underflow\n");
        return;
    }

    printf("Deleted root: %d\n", h->arr[0]);

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void display(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    MinHeap h;
    initHeap(&h);
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&h, val);
                break;
            case 2:
                deleteRoot(&h);
                break;
            case 3:
                display(&h);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
