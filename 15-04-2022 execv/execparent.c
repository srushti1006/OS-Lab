#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int array[], int size)
{

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
	int number,data[20],i=0;
	printf("Enter 5 numbers");
	number=5;
	while(i<number)
	{
		printf("Enter %d number: ",i+1);
		scanf("%d",&data[i++]);
	}
	printf("Parent will sort data and child will search now");

	  
	// find the array's length
	int size = number;

	bubbleSort(data, size);
	
	printf("Sorted Array in Ascending Order:\n");
	printArray(data, size);
		
	char datac[5][2] = {'\0'};
	i=0;
	while(i<number)
	{
		sprintf(datac[i],"%d",data[i]);
		i++;
	}
	char *datacp=NULL;
	datacp=*datac;
	char *args[]={"./execchild",datacp,NULL};
        execvp(args[0],args);        
        printf("execParent EndingReturn not expected. Must be an execv error.n");
     
    return 0;
}
