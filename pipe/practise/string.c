#include <string.h>
#include <sys/types.h> //forking
#include <unistd.h> //pipe and dup2
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

char* rev(char* string)  //string reversal
{
	int i=strlen(string)-1;
	int j=0;
	char ch;
	while(i>=j)
	{
		ch=string[i];
		string[i]=string[j];
		string[j]=ch;
		i--;
		j++;
	}
	printf("\nthe reversed string is %s\n",string);
	return(string);

}


int main()
{
	int fd[2];
	int pid;
	char readbuffer[50];
	pipe(fd);
	char string[50];

	pid=fork();
	if(pid==0)//child process takes the string input from the user  writing on to the pipe 
	{
		printf("\nenter the string\n");
		scanf("%s",string);
		printf("\nyou have entered the string %s\n",string);

		close(fd[0]);
		dup2(fd[1],1);//reading into the pipe
		printf("%s",string);
		close(fd[1]);
		exit(0);
	}
	else if(pid>0)//parent process reads from the pipe
	{
		wait(0);
		close(fd[1]);
		read(fd[0],readbuffer,sizeof(readbuffer));
		printf("%s\n",readbuffer );
		char original[50];
		close(fd[0]);
		strcpy(original,readbuffer);
		char *here = rev(readbuffer);
		printf("%s\n",here );
		if(strcmp(here,original)==0)
		{
			printf(" \npallindrome\n ");
		}
		else 
		{
			printf(" \nnot pallindrome\n ");
		}


	}	





	}








