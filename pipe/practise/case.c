#include <unistd.h>//for pipes and dup2
#include <sys/types.h>//for forking
#include <sys/wait.h>//for wait function
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int fd[2];//file descriptors
	char readbuffer[20];//for pipe reading
	int nbytes;
	pipe(fd);//set up the pipe using unistd.h
	int pid=fork();//creating 2 process
	if(pid==0) //child process
	{
		dup2(fd[1],1);//duplicating the stdout fd  open for writng
		execlp("ls","ls",NULL);
		exit(0);

	}
	else if(pid>0)//read from the pipe
	{
		// dup2(fd[0],0);//duplicating the stdin  fd open for readd
		// execlp("tr","tr","a-z","A-Z");
		// exit(0);
		wait(NULL);

		while((nbytes=read(fd[0],readbuffer,strlen(readbuffer)+1))>0)
		{
			int i;
			for(i=0;i<nbytes;++i)
			{
				readbuffer[i]=toupper(readbuffer[i]);

			}
			printf("%s",readbuffer);
		}


    
	}
	else{
		printf("\nerror in forking\n");
	}

return(0);

}
