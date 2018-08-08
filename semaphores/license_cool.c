#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t mutex;
time_t t;
int data = 100,rcount = 0,n=0,m=0;

void *reader(void *arg)
{
int f;
f = ((int)arg);

sem_wait(&mutex);

if(rcount < n)
{
	rcount=rcount+1;
	data=rand()%50;
	printf("\nSoftware accessed by the User %d produces result %d",f+1,data);
	sleep(1);
	rcount = rcount - 1;
	sem_post(&mutex);
}

else
{
	sem_post(&mutex);
	printf("\nMaximum limit reached. User %d didn't receive access",f+1);
}
}


int main()
{
int i,b;
srand((unsigned) time(&t));
pthread_t rtid[10];
sem_init(&mutex,0,1);

printf("\nEnter the total no of users: ");
scanf("%d",&m);

printf("\nEnter the no. of licenses that can be allowed to access concurrently: ");
scanf("%d",&n);


printf("\nDisplaying scenario in which %d users are trying simultaneously and one user is trying after all other users finish\n",m-1);
m--;
for(i=0;i<m;i++)
{

pthread_create(&rtid[i],NULL,reader,(void *)i);
}

for(i=0;i<m;i++)
{
pthread_join(rtid[i],NULL);
}

pthread_create(&rtid[i],NULL,reader,(void *)i);
pthread_join(rtid[i],NULL);
printf("\n\n");
}
