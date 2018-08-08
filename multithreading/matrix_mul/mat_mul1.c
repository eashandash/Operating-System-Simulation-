#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define M 3
#define K 2
#define N 3

#define threads 10

int a[M][K] = {{1,4}, {2,5}, {3,6}};
int b[K][N] = {{8,7,6}, {5,4,3}};
int c[M][N];


struct v 
{
	int i;		// row 
	int j;		// column
};

void *runner(void *param) {
	struct v *data = param;

	int n, sum = 0;
	for (int i=0; i < K; i++) {
		sum += a[data->i][i]*b[i][data->j];
	}

	// assign the sum to its coordinates
	c[data->i][data->j] = sum;

	// exit thread
	pthread_exit(0);
}

int main() {

	int count = 0;

	for (int i=0; i < M; i++) {
		for (int j=0; j < N; j++) {
			struct v *data = (struct v*) malloc(sizeof(struct v));

			data->i = i;
			data->j = j;

			// now create the thread passing it data as a parameter
			pthread_t tid;
			//pthread_attr_t attr;

			//get the thread attributes
			//pthread_attr_init(&attr);

			//create the thread
			pthread_create(&tid, NULL, runner, data);

			pthread_join(tid, NULL);
			//count++;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j=0 ;j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
