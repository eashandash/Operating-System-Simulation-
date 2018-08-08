#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd[2],bytes;
	char readbuffer[100];
	int pid;
	char string[]="wassup dude  how are u ?";
	pipe(fd);
	pid=fork();

	if(pid>0)//parent process writnig onto the pipe
	{
		close(fd[0]);
		bytes=write(fd[1],string,(strlen(string)+1));
		printf("\nwritten on to the pipe %s of size %d\n",string,bytes);
		close(fd[1]);
	}
	else if(pid==0)//child process reading from the pipe 
	{

		close(fd[1]);
		bytes=read(fd[0],readbuffer,sizeof(readbuffer));
		printf("\nread from the pipe %s of size %d\n",readbuffer,bytes);
		close(fd[0]);

	}


return(0);
}