#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("enter the value of n");
	int n;
	int a[n];
	scanf("%d",&n);
	printf("enter the array");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int pid = vfork();

	if (pid == 0)
	{


	printf("\nHello from Child! parent id: %d my id: %d \n",getppid(),getpid());

		for(int i=n/2;i<n;i=i+1)
		{
			for(int j=n/2;j<n;j=j+1)
			{
			  if(a[j]<=a[j+1])
			  {
			    int temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
			  }
			}
		}

		printf("Half Descending array is:\n");
		for(int i=n/2;i<n;i=i+1)
			printf("%d ",a[i]);

		printf("\n");
		exit(0);

	}
	 else if(pid > 0)
	{
		wait(NULL);
		//PARENT Ascending

		printf("\nHello from Parent! parent id: %d my id: %d \n",getppid(),getpid());

		int i,j,temp;
		for(int i=0;i<n/2;i=i+1)
		{
			for(int j=0;j<n/2;j=j+1)
			{
			  if(a[j]>=a[j+1])
			  {
			    int temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
			  }
			}
		}

		printf("Half Ascending array is:\n");
		for(int i=0;i<n/2;i=i+1)
			printf("%d ",a[i]);

		printf("\n\n");
				
	} 

	else
	{
		printf("\nFailed to fork process 1\n");
        exit(1);
	}  
	
	printf("Half Ascending and Half Descending array is:\n");
	for(int i=0;i<n;i=i+1)
			printf("%d ",a[i]);





	return(0);
}