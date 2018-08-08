#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	printf("enter the value of n ");
	
	
	int n;
	scanf("%d",&n);
	int a[n];
	int pid=vfork();
	if(pid==0)
	 {
	 	for (int i = 1; i < n ; i = i + 2)
    	{
	    	
	    	a[i] = i;
    	}
    	exit(0);

	}
	else if(pid>0)
	{
		for (int i = 0; i < n ; i = i + 2)
    	{
	    	a[i] = i;
    	}
	}
	else if(pid<0)
	{
		printf("no process creation");
	}

	for (int i = 0; i < n; ++i)
		printf("%d  ",a[i] );
	
	printf("parent id --%d my id --%d\n",getppid(),getpid());

	return(0);
}