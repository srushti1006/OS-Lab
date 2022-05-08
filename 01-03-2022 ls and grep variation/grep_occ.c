#include<stdio.h>
#include<string.h>
#define max 1024
#define WHITE  "\033[0;37m"
void usage()
{
	printf("usage:\t. /a.out filename word \n ");
}
int main(int argc, char *argv[])
{
	FILE *fp;
	char fline[max];
	char flag[max];
	char *newline;
	int count=0;
	int occurrences=0;
	if(argc!=3)
	{
		usage();	
		exit(1);
	}	
	if(!(fp=fopen(argv[1], "r")))
	{
		printf("grep: couldnot open file : %s \n",argv[1]);
		exit(1);
	}
	while(fgets(fline,max,fp)!=NULL)
	{
		count++;
		//if(newline=strchr(fline, '\n'))
//		*newline="\0";
		if(strstr(fline,argv[2])!=NULL)
		{
			int countlinewise = 0;
			const char *tmp = fline;
			while(tmp = strstr(tmp, argv[2]))
			{
			   countlinewise++;
			   tmp++;
			}
			
			//printf("%s\n",fline);
			printf(WHITE "%s: %d %sno of occurences in line no %d is %d\n", argv[1],count, fline,count,countlinewise);
			printf("--------------------\n");
			occurrences++;
		}
	}
	printf("--------------------\nTotal No of lines having this pattern is %d",occurrences);
}

