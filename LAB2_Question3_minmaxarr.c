#include <stdio.h>

int main()
{
    int arr[100];
    int i, n, max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d array elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    max = arr[0];
    min = arr[0];

    
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Max value in the array: %d\n", max);
    printf("Min value in the array: %d\n", min);
    
    return 0;
}
