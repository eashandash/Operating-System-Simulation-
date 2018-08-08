#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//for dup2 function
#include <sys/types.h>
#include <sys/wait.h>//for wait function
#include <string.h>//for strlen function
#include <ctype.h>//for toupper function
#define size 50

char *strrev(char *str)
{
    int i = strlen(str)-1,j=0;

    char ch;
    while(i>=j)
    {
        ch = str[i];
        str[i]= str[j];
        str[j] = ch;
        i--;
        j++;
    }
    printf("reversed it to %s\n",str );
    return str;
}

int main(void)
{
    //fd is a file descriptor where fd[0] has a read end and fd[1] has a write end
    //nbytes will take the number of bytes we
    int     fd[2], nbytes;
    char    readbuffer[size];

    pipe(fd);

    int pid = fork();

    if(pid == 0)
    {
        /* Child process closes up input side of pipe */
        printf("Enter a sring to check whether it is palindrome or not: ");
        scanf("%s",readbuffer);
        printf("You entered %s\n",readbuffer );
        close(fd[0]);
        dup2(fd[1],1);
        printf("%s",readbuffer);
        close(fd[1]);
        exit(0);
    }
    else if(pid > 0)
    {

        /* Parent process closes up output side of pipe */
        wait(0);
        close(fd[1]);
        char scanbuffer[size];
        nbytes = read(fd[0], scanbuffer, size);
        printf("I received %s\n",scanbuffer );
        char word[size];
        strcpy(word,scanbuffer);
        strrev(scanbuffer);
        if (strcmp(word,scanbuffer) == 0)
            printf("Entered string is a palindrome.\n");
        else
            printf("Entered string is not a palindrome.\n");

        close(fd[0]);
    }

	else
    {
            printf("\nBro your fork is wrong\n");
            exit(1);
    }
        return(0);
}
