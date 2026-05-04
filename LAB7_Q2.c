#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for(int i=0;i<SIZE;i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return (key % 1000) % 10;
}

void insert(int key) {
    int index = hashFunction(key);

    if(hashTable[index] != -1) {
        printf("Collision occurred at index %d!\n", index);
        return;
    }

    hashTable[index] = key;
    printf("Inserted successfully.\n");
}

void deleteKey(int key) {
    int index = hashFunction(key);

    if(hashTable[index] == key) {
        hashTable[index] = -1;
        printf("Deleted successfully.\n");
    } else {
        printf("Key not found.\n");
    }
}

void search(int key) {
    int index = hashFunction(key);

    if(hashTable[index] == key)
        printf("Key found at index %d\n", index);
    else
        printf("Key not found.\n");
}

void display() {
    for(int i=0;i<SIZE;i++)
        printf("%d : %d\n", i, hashTable[i]);
}

int main() {
    int choice, key;
    initialize();

    do {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d",&key);
                deleteKey(key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d",&key);
                search(key);
                break;
            case 4:
                display();
                break;
        }
    } while(choice!=5);

    return 0;
}
