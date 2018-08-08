#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("enter the value of n");
	int n;
	scanf("%d",&n);
	int pid=fork();
	if(pid==0)
	{
		int x=0;
		int y=1;
		printf("\n %d",x);
		printf(" %d",y);
		for(int i=0;i<n-2;i++)
		{
			int z=x+y;
			x=y;
			y=z;
			printf(" %d",z);

		}
	}
	else if(pid>0)
	{
			int flag = 1, num = 0, data = 2;

		while (num < n) 
		{
			for (int i = 2; i <= data - 1; i++)
			 {
				if (data % i == 0) 
				{
					flag = 0;
					break;
				}
			}

			/* print prime numbers alone */
			if (flag) 
			{
				printf("%d ", data);
				num = num + 1;
			}

			data = data + 1;
			flag = 1;
		}
		
	}
}