#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//for dup2 function
#include <sys/types.h>
#include <sys/wait.h>//for wait function
#include <string.h>//for strlen function
#include <ctype.h>//for toupper function
#define size 1024
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
        close(fd[0]);
        //whatever you write below dup2 will be written into fd[1]
        dup2(fd[1],1);
        FILE *fp;
        fp = fopen("test.txt","r");
        char *line;

        while(fgets(line, 1024, fp) != NULL)
            printf("%s",line);

        close(fd[1]);
        exit(0);
    }
    else if(pid > 0)
    {

        /* Parent process closes up output side of pipe */
        wait(0);

        
        close(fd[1]);

        
        nbytes = read(fd[0],readbuffer,size);

        //display the contents of the file
        for (int i = 0; i < nbytes; ++i)
            printf("%c",readbuffer[i]);
        printf("\n");

        printf("\nThe total number of characters(a..z|A...Z) in the given text are:");
        //to count the number of characters
        int CharCount = 0;

        for (int i = 0; i < nbytes; ++i)
            if(readbuffer[i] != '.' && readbuffer[i] != ' ' && readbuffer[i] != ',' && readbuffer[i] != '\0'  && readbuffer[i] != '-' && readbuffer[i] != '\n' )
                CharCount = CharCount + 1;

        printf("%d\n",CharCount);

        printf("\nThe total number of words in the given text are:");
        //to count the number of words
        int WordCount = 1;

        for (int i = 0; i < nbytes; ++i)
            if(readbuffer[i] == ' ' || readbuffer[i] == '\n' || readbuffer[i] == '.')
                WordCount = WordCount + 1;

        printf("%d\n",WordCount);

        printf("\nThe total number of lines in the given text are:");
        //to count the number of words
        int LineCount = 1;

        for (int i = 0; i < nbytes; ++i)
            if(readbuffer[i] == '\n')
                LineCount = LineCount + 1;

        printf("%d\n",LineCount);

        printf("\nThe total number of sentences in the given text are:");
        //to count the number of words
        int SentenceCount = 0;

        for (int i = 0; i < nbytes; ++i)
            if(readbuffer[i] == '.')
                SentenceCount = SentenceCount + 1;

        printf("%d\n",SentenceCount);

        close(fd[0]);
    }

	else
    {
            printf("\nBro your fork is wrong\n");
            exit(1);
    }
        return(0);
}
