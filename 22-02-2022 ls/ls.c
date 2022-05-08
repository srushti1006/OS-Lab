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
	while(d=readdir(p))
	{
		  printf("%s\n",d->d_name);
	}
}
/*
//Take input using printf and scanf
#include<stdio.h>
#include<dirent.h>
int main()
{
	char dirname[50];
	DIR*p;
	struct dirent *d;
	printf("Enter directory name\n");
	scanf("%s",dirname);
	p=opendir(dirname);
	if(p==NULL)
	{
	  perror("Cannot find directory");
	  return 0 ;
	}
	while(d=readdir(p))
	{
		printf("%s\n",d->d_name);
	}
}
*/
