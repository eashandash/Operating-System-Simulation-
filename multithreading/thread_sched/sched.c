#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

char* str1="firefox";
char* str2="google-chrome";
char* str3="./sum";
char* str4="./matmul";
char* str5="./quicksort";
char* str6="./inv";


void* runner(void* para)
{
	// char*str=calloc(1,sizeof(para));
	// str=para;
	// system(str);
	// pthread_exit(0);

	system(para);
	pthread_exit(0);


}


int main()
{
	pthread_t tid[5];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_attr_setschedpolicy(&attr,SCHED_FIFO);

	pthread_create(&tid[0], &attr, runner,str1);
	pthread_create(&tid[1], &attr, runner,str2);
	pthread_create(&tid[2], &attr, runner,str3);
	pthread_create(&tid[3], &attr, runner,str4);
	pthread_create(&tid[4], &attr, runner,str5);
	pthread_create(&tid[5], &attr, runner,str6);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	pthread_join(tid[5], NULL);

	return 0;





}