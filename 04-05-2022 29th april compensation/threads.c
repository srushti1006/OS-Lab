/*to run this file the command:
gcc  main.c -o main -lpthread
//main is the c file ka naam*/	
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
pthread_t tid[2]; 
void* doSomeThing(void *arg) 
{ 
 unsigned long i = 0; 
 pthread_t id = pthread_self(); 
 if(pthread_equal(id,tid[0])) 
 { 
 printf("\n First thread processing\n"); 
 } 
 else 
 { 
 printf("\n Second thread processing\n"); 
 } 
 for(i=0; i<(0xFFFFFFFF);i++); 
 return NULL; 
} 
int main(void) 
{ 
 int i = 0;
 
int err; 
 while(i < 2) 
 { 
 err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);  
if (err != 0) 
printf("\n can't create thread :[%s]", strerror(err));  else
 printf("\n Thread created successfully\n"); 
 i++; 
 } 
 sleep(5); 
 return 0; 
} 

/*output
 Thread created successfully

 First thread processing

 Thread created successfully

 Second thread processing
*/

