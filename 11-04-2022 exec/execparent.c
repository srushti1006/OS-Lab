#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main()
{
        //A null terminated array of character
        //pointers

	int data[] = {10, 30, 20, 50, 40};
	printf("Parent will sort data and child will search now");

	  
	// find the array's length
	int size = sizeof(data) / sizeof(data[0]);

	bubbleSort(data, size);
	
	printf("Sorted Array in Ascending Order:\n");
	printArray(data, size);
	char data[][] ={"10","20","30","40","50"};
	char **datap=data;
	char *args[]={"./execchild",*datap,NULL};
        execvp(args[0],args);

        
        printf("execParent EndingReturn not expected. Must be an execv error.n");
     
    return 0;
}
