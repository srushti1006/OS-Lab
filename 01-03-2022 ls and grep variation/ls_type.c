//Take input using main function
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
int main(int argc,char **argv)
{
	DIR*p;
	struct dirent *d;
	p=opendir(argv[1]);
	if(p==NULL)
	{
	  perror("Cannot find directory");
	  return 0 ;
	}
	printf("Program to print type of file \nIf type = 4 then it is a hidden file and if it is 8 then it is a file\n");
	while(d=readdir(p))
	{
		 printf("Name of file %s\n",d->d_name);
		 printf("Type of file %d\n",d->d_type);
	}
	
}
