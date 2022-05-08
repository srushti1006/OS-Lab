#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid,pid1,pid2;
	int a = 3,b=5;
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
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
		printf("Addition of two numbers: %d\n",a+b);
		
	}
	else
	{
		pid2 = getpid();
		printf("The process id of child is %d\n",pid2);
		printf("Subtraction of two numbers: %d\n",a-b);
	}
	return 0;
}


