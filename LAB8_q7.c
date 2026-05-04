#include <stdio.h>

int binarySearchRecursive(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);

        return binarySearchRecursive(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    
    int result = binarySearchRecursive(arr, 0, n - 1, key);
    
    if (result == -1)
        printf("Element %d is not present in array\n", key);
    else
        printf("Element %d is present at index: %d\n", key, result);
        
    return 0;
}
