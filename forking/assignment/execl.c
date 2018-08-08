#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid=fork();
	if(pid==0)//child process
	{
		printf("\nthis is child process in execution\nparent id %d and current id %d",getppid(),getpid());
		execl("/media/eashan/New Volume/CODES/5th sem/Operating_system/forking/assignment/test","test",NULL);
	}
	else if(pid>0)//parent process
	{
		wait(NULL);
		printf("\nthis is parent process in execution\nparent id %d and current id %d",getppid(),getpid());

	}
	else
	{
		printf("forking error no process creation ");

	}
	return(0);
}