#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX];
int front = -1;
int rear = -1;

void enqueue(char c) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = c;
}

char dequeue() {
    if (front == -1 || front > rear) {
        return '\0';
    }
    char c = queue[front];
    front++;
    return c;
}

int main() {
    char str[MAX];
    int i, len, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = 0;
    while (str[len] != '\0') {
        len++;
    }

    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    for (i = len - 1; i >= 0; i--) {
        if (str[i] != dequeue()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
