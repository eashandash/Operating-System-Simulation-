#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h> /* for sleep */

const int process=5;
const int res=3;

/*req datastrcuture
1.allocated
2.available
3.need
4.max
*/

int calculate_need(int need[process][res],int max[process][res],int allocated[process][res])
{
	for(int i=0;i<process;i++)
	{
		for(int j=0;j<res)
		{
			need[i][j]=max[i][j]-allocated[i][j];
		}
	}

}



int main()
{
  int pro[] = {0, 1, 2, 3, 4};
  printf("\nenter the no of instances of each resources :\n")
  for(int i=0;i<res;i++)
  {
  	printf("\nthe instances for resource %d  ")
  	scanf("%d",&available[i]);
  }


}