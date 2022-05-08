#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        //A null terminated array of character
        //pointers
        char *args[]={"./exec",NULL};
        execvp(args[0],args);
     
        
        printf("execDemo Ending-----");
     
    return 0;
}
