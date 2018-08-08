
#define MAX_SIZE 5
/*main.c*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

/*the semaphores*/
sem_t Number;
sem_t mutex;

/*buffer counter*/
int count = MAX_SIZE;

void *lic_use(void *param)
{
	sleep(2);
	int k = (int *) param;
	
	
		printf("User %d requested for access to the software\n",k);
		sleep(1);
		sem_wait(&Number);
		
		if(count == 0)
			printf("Exhausted of liscences.\n");
		else
		{
			count = count - 1;
			printf("User %d got permission\n", k);
			sleep(1);
			printf("USER %d is accessing the software\n",k);
			//system("./quicksort");
		    system("./sum");
		} 
		
		sem_post(&Number);
		printf("User %d finished using the software\n",k);
	 sleep(2);
	
}


int main(int argc,char *argv[])
{
	int i,no_read;
	printf("Enter the number of Users: ");
	scanf("%d",&no_read);
	pthread_t user_thread[no_read];
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	sem_init(&Number,0,MAX_SIZE);

	for(i = 0;i < no_read;i++)
		pthread_create(&user_thread[i],&attr,lic_use,(void *)i);

	for(i = 0;i < no_read;i++)
		pthread_join(user_thread[i],NULL);

	printf("Exiting the Program..\n");
	sleep(1);
	exit(0);
}
