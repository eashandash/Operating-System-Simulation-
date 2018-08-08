#include <stdio.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define s1 "/mutex1"
#define s2 "/mutex2"

sem_t *mut1, *mut2;

void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("\n1:received SIGINT\n");
        sem_post(mut2);
        printf("2:Released s2\n");
        exit(EXIT_SUCCESS);
    }
}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)

    if((mut1 = sem_open(s1, O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
        perror("mut1");
    if((mut2 = sem_open(s2, O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
        perror("mut2");

    sem_wait(mut2);
    printf("2:Acquired s2\n");

    sleep(10);

    sem_wait(mut1);
    printf("2:Acquired s1!!\n");

    sem_post(mut1);
    sem_post(mut2);

    sem_unlink(s1);
    sem_unlink(s2);
}
