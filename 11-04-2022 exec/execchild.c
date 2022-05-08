#include<stdio.h>
#include<unistd.h>
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
int main()
{
	int i;	
	printf("I am execchild.c called by execvp() I will search data now");
	printf("%d",args[1]);
	int n = sizeof(array) / sizeof(array[0]);
	int x = 4;
	int result = binarySearch(array, x, 0, n - 1);
	if (result == -1)
	printf("Not found");
	else
	printf("Element is found at index %d", result);
	printf("\n");
     
    return 0;
}
