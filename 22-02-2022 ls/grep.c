#include<stdio.h>
#include<string.h>
#define max 1024
void usage()
{
	printf("usage function \t /a.out filename word \n");
}
int main(int argc, char *argv[])
{
	FILE *fp ;
	char fline[max] ;
	char *newline ;
	int count = 0 ;
	int occurences = 0 ;
	if(argc != 3)
	{
		usage() ;
		exit(1) ;
	}
	if(!(fp=fopen(argv[1],"r")))
	{
		printf("grep: could not open file : %s \n" , argv[1]);
		exit(1) ;
	}
	while(fgets(fline,max,fp) != NULL)
	{
		count ++ ;
	}
	if(newline = strchr(fline, '\n'))
	{	
		*newline = '\0' ;
		if(strstr(fline, argv[2] != NULL))
		{
			printf("%s: %d %s \n",argv[1],count,fline) ;
			occurences ++ ;
		}
	}
}	
		
