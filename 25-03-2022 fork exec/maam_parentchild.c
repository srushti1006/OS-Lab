#include<stdio.h>
#include<unistd.h>
#include<string.h>

/*Main Function*/
int main(int argc , char **argv)
{
int first, last, middle, n ,key, array[100], i, sum=0;
printf("\n Inputs count = %d",argc);
for(i=0;i<argc;i++)
{
array[i]=atoi(argv[i]);/*atoi for conversion of string to

int*/

printf("\n %d",array[i]);
}
printf("\n Enter value to find : \n");
scanf("%d",&key);
/*Binary Search*/
n=argc;
first=0;
last=n-1;
middle=(first+last)/2;
while( first <= last)
{
if(array[middle] < key)
first=middle + 1;
else if(array[middle] == key)
{
printf("\n%d found at location %d.\n",key,middle+1);
break;
}
else
last = middle - 1;
middle = (first + last )/2;

}
if( first > last)
{

printf("\n The element [%d] does not exist in the

list.\n",key);
}
return 0;
}

---------------------------------------------------

#include<stdio.h>/*Used for printf and scanf*/
#include<unistd.h>/*Used for exec function types*/
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>/*Used for string copy fun*/

/*Function Declaration*/
void quicksort(int[] ,int,int);/*Quick Sort*/

/*Main Function*/
int main(void)
{
int pid = 0 ;/*Variable to store the pid*/
int value = 0;
int list[50] = {0};/*Accept elements to sort*/
char **buffer ;
int size = 0;/*Used for no. of elements to sort*/
int i =0;/*Used for 'for loop'*/
int x=0;
/*Accept no. of elements to sort*/
printf("\n\t Enter the number of elements: ");
scanf("%d",&size);

/*Accept Elements*/
printf("\n\t Enter the elements to be sorted : \n");
for(i=0;i<size;i++)
{
printf("\n\t Enter the %d element : \t",i+1);
scanf("%d",&list[i]);

}
buffer = malloc(size*sizeof(char*));
for(i=0;i<size;i++)
{
buffer[i]=malloc(size*sizeof(char));
}
pid=fork();/*now create new process*/
printf("\n\t PARENT PROCESS = %d \n ",getppid());
/*Sort Elements*/
quicksort(list,0,size-1);
printf("\n\tafter applying quicksort \n");
for(i=0;i<size;i++)
{
printf("\t%d\t",list[i]);
}
printf("\n");
for(i=0 ; i<size; i++)
{
sprintf(buffer[i],"%d",list[i]);/*buff to store size in

bytes*/
}
buffer[i]='\0';
execve("child",buffer,NULL);/*executes an existing file*/
return 0;
}

/*Quick Sort*/
void quicksort(int list[],int low,int high)
{
int pivot,i,j,temp;
if(low < high)
{
pivot = low;//select pivot element
i= low;
j=high;
while(i < j)
{

while(list[i] <= list[pivot] && i <= high)//increment i

when pivot is greater
{
i++;
}
while(list[j] > list[pivot] && i >= low)//decrement j

when pivot is greater
{
j--;
}
if(i < j)//when i < j then perform swap
{
temp = list[i];
list[i] = list[j];
list[j] = temp;
}
}
temp=list[j];
list[j]= list[pivot];
list[pivot] = temp;
quicksort(list,low,j-1);
quicksort(list,j + 1,high);
}
}
/*
gcc child.c -o child
 gcc parent.c
 ./a.out
Enter the number of elements: 3
Enter the elements to be sorted :
Enter the 1 element : 3
Enter the 2 element : 2
Enter the 3 element : 1
PARENT PROCESS = 8150
after applying quicksort
1 2 3

Inputs count = 3
1
2
3
Enter value to find :
PARENT PROCESS = 9634
after applying quicksort
1 2 3
Inputs count = 3
1
2
3
Enter value to find :
2
2 found at location 2.
*/
