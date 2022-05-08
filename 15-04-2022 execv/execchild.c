#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}
int main(char *args[])
{
	int i;	
	printf("I am execchild.c called by execvp() I will search data now");
	int array[5]={0};
	char *arr=args[1];
	int n = 5,j=0;
	
	while(i<n)
	{
		array[i]=atoi(arr[i]);
	}
	
	int x = 4;
	printf("Enter data to be found ");
	scanf("%d",&x);
	int result = binarySearch(array, x, 0, n - 1);
	if (result == -1)
	printf("Not found");
	else
	printf("Element is found at index %d", result);
	printf("\n");
     
    return 0;
}
