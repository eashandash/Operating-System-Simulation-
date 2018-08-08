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
		sleep(5);
		printf("\nthis is child process in execution\nparent id %d and current id %d",getppid(),getpid());
		printf("the child is an orphan now");

	}
	else if(pid>0)
	{
		printf("\nthis is parent process in execution\nparent id %d and current id %d",getppid(),getpid());

	}
	else
	{
		printf("forking error no process creation ");

	}

	return(0);
}