#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int pid = fork();
	if (pid == 0)
	{
        //CHILD 
        sleep(1);
        printf("\nHey iam on CPU Second   (CHILD)\n");
		printf("\nHello from Child! parent id: %d my id: %d \n",getppid(),getpid());
   	}
 
    else if(pid > 0)
	{
		//PARENT
		printf("\nHey iam on CPU First   (PARENT)\n");
		printf("\nHello from Parent! parent id: %d my id: %d \n\n",getppid(),getpid());
					
	} 
	else
	{
		printf("\nFailed to fork process 1\n");
        exit(1);
	}  
	       
	return(0);
}