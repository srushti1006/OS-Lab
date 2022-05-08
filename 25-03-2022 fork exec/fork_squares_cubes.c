#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid,pid1,pid2;
	int a[5]={'\0'};
	int s[5]={'\0'};
	int c[5]={'\0'};
	printf("Enter 5 numbers: ");
	for(int i=0;i<5;i++)
	{		
		scanf("%d",&a[i]);
	}
	pid=fork();
	if(pid==-1)
	{
		printf("Error in process creation\n");
		return -1;
	}
	if(pid!=0)
	{
		pid = getpid();
		printf("The process id of parent is %d\n",pid1);
		printf("Squares of array :\n");
		for(int i=0;i<5;i++)
		{		
			s[i] = a[i]*a[i];
			printf("Square of %d is %d \n",a[i],s[i]);
		}
	}
	else
	{
		pid2 = getpid();
		printf("The process id of child is %d\n",pid2);
		printf("Cubes of array :\n");
		for(int i=0;i<5;i++)
		{		
			c[i] = a[i]*a[i]*a[i];
			printf("Cube of %d is %d\n",a[i],c[i]);
		}
		
	}
	return 0;
}

