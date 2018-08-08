#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char* cmd[]={"ls", NULL};
	int pid=fork();
	if(pid==0)//child process
	{
		sleep(2);
		printf("\nthis is child process in execution\n parent id %d and current id %d",getppid(),getpid());
		//execv("/media/eashan/New Volume/CODES/5th sem/Operating_system/forking/assignment/test",cmd);
		execv("./test",cmd);
	}
	else if(pid>0)//parent process
	{
		//wait(NULL);
		printf("\nthis is parent process in execution\nparent id %d and current id %d",getppid(),getpid());

	}
	else
	{
		printf("forking error no process creation ");

	}
	return(0);
}