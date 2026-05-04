#include <stdio.h>

void linearSearchAll(int arr[], int n, int key) {
    int found = 0;
    printf("Searching for %d...\n", key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index: %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element %d does not exist in the array.\n", key);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 4, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Test case 1: Element with multiple occurrences
    linearSearchAll(arr, n, 4);
    
    printf("\n");
    
    // Test case 2: Element not in array
    linearSearchAll(arr, n, 7);
    
    return 0;
}
