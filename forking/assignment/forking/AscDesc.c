#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n;

	printf("Enter the value of n(size of array)\n");
	scanf("%d",&n);

	int a[n];

	printf("Enter the numbers\n");
	for(int i=0;i<n;i=i+1)
		scanf("%d",&a[i]);

	printf("The entered numbers are: ");

	for(int i=0;i<n;i=i+1)
		printf("%d ",a[i]);

	printf("\n");

	int pid = fork();

	if (pid == 0)
	{
		//Child Descending
		printf("\nHello from Child! parent id: %d my id: %d \n",getppid(),getpid());

		for(int i=0;i<n;i=i+1)
		{
			for(int j=0;j<n-1-i;j=j+1)
			{
			  if(a[j]<=a[j+1])
			  {
			    int temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
			  }
			}
		}

		for(int i=0;i<n;i=i+1)
			printf("%d ",a[i]);

		printf("\n");

   	}
 
    else if(pid > 0)
	{
		wait(NULL);
		//PARENT Ascending

		printf("\nHello from Parent! parent id: %d my id: %d \n\n",getppid(),getpid());

		int i,j,temp;
		for(int i=0;i<n;i=i+1)
		{
			for(int j=0;j<n-1-i;j=j+1)
			{
			  if(a[j]>=a[j+1])
			  {
			    int temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
			  }
			}
		}

		for(int i=0;i<n;i=i+1)
			printf("%d ",a[i]);

		printf("\n");
				
	} 

	else
	{
		printf("\nFailed to fork process 1\n");
        exit(1);
	}  
	
	printf("parent id --%d my id --%d\n",getppid(),getpid());
       
	return(0);
}