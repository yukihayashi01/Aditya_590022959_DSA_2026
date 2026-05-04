
#include <stdio.h>

int main()
{
	int arr[100];
	int i=0,n;
	
	printf("Enter the array length");
	scanf("%d",&n);
	
	printf("Enter array Elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("The array elements is");
	for(i=0;i<n;i++)
	{
		printf("%d",&arr[i]);
	}

	return 0;
}

