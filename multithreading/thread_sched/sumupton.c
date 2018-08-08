#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum;

void * sumfunction(void * parameter)
{
	// char ** argv=parameter;
	int *x = parameter;
	printf("para %d\n",*x);
	sum=((*x)*((*x)+1))/2;
	pthread_exit(0);
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number\n");
	scanf("%d" , &n);
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, sumfunction, &n);
	pthread_join(tid, NULL);
	printf("Sum is %d\n", sum);
	return 0;
}