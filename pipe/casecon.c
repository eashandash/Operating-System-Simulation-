#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
		wait(NULL);
		// while((bytes=read(fd[0],readbuffer,strlen(readbuffer)+1))>0)
		// {
		// 	for(int i=0;i<bytes;++i)
		// 	{
		// 		readbuffer[i]=toupper(readbuffer[i]);
				

		// 	}
		// 	printf("%s",readbuffer);
		// }

		dup2(fd[0],0);
		execlp("tr","tr","a-z","A-Z");
		exit(0);





	}
	else if(pid==0)//child process reading from the pipe 
	{

		dup2(fd[1],1);
		execlp("ls","ls",NULL);
		exit(0);

	}


return(0);
}