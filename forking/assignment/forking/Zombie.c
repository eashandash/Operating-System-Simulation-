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
        printf("\nHey iam on CPU First  (CHILD)\n");
		printf("\nHello from Child! parent id: %d my id: %d \n",getppid(),getpid());

   	}
 
    else if(pid > 0)
	{
		//PARENT
		wait(0);
		printf("\nHey iam on CPU Second  (PARENT)\n");
		printf("\nHello from Parent! parent id: %d my id: %d \n\n",getppid(),getpid());

				
	} 
	else
	{
		printf("\nFailed to fork process 1\n");
        exit(1);
	}  
	       
	return(0);
}