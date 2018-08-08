#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("enter the value of n");
	int n;
	scanf("%d",&n);
	int a[n];

	printf("Enter the numbers\n");
	for(int i=0;i<n;i=i+1)
	{
		scanf("%d",&a[i]);
	}

	int pid = fork();

	if (pid == 0)//Child Descending
	{
		
		printf("\nThis is Child! Descending order --> parent id: %d current id: %d \n",getppid(),getpid());

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

   	 else if(pid > 0)//PARENT Ascending
	{
		wait(NULL);
		

		printf("\nThis Parent! Ascending order --> parent id: %d current id: %d \n\n",getppid(),getpid());

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
		printf("\nfailed process creation\n");
        exit(1);
	}  
	
       
	return(0);









}