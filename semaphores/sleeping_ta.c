
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> // The maximum number of student threads.
#define MAX_STUDENTS 25 // Function prototypes...

void *student(void *num);
void *TA(void *);
void randwait(int secs);

//Define the semaphores.
// waitingRoom Limits the # of customers allowed  to enter the waiting room at one time.
sem_t waitingRoom;
// taChair ensures mutually exclusive access to the TA chair.
sem_t taChair;
// taPillow is used to allow the TA to sleep until a student arrives.
sem_t taPillow;
// seatBelt is used to make the student to wait until the TA is done clearing the doubts.
sem_t seatBelt;
// Flag to stop the TA thread when all customers have been serviced.
int allDone = 0;

int main(int argc, char *argv[])
{
    pthread_t btid;
    pthread_t tid[MAX_STUDENTS];
    int i, x, numStudents, numChairs; int Number[MAX_STUDENTS];
    printf("Maximum number of students can only be 25. Enter number of students and chairs.\n");
    scanf("%d",&x);
    numStudents = x;
    scanf("%d",&x);
    numChairs = x;
    if (numStudents > MAX_STUDENTS) {
       printf("The maximum number of Students is %d.\n", MAX_STUDENTS);
       system("PAUSE");   
       return 0;
    }
    printf("\t\tA solution to the sleeping TA problem using semaphores.\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        Number[i] = i;
    }
    // Initialize the semaphores with initial values...
    sem_init(&waitingRoom, 0, numChairs);
    sem_init(&taChair, 0, 1);
    sem_init(&taPillow, 0, 0);
    sem_init(&seatBelt, 0, 0);
   
    // Create the TA.
    pthread_create(&btid, NULL, TA, NULL);
   
    // Create the customers.
    for (i = 0; i < numStudents; i++) {
        pthread_create(&tid[i], NULL, student, (void *)Number[i]);
    }
    // Join each of the threads to wait for them to finish.
    for (i = 0; i < numStudents; i++) {
        pthread_join(tid[i],NULL);
    }
    // When all of the customers are finished, kill the TA thread.
    allDone = 1;
    sem_post(&taPillow); // Wake the TA so he will exit.
    pthread_join(btid,NULL);
    system("PAUSE");   
    return 0;
}

void *student(void *number) {
     int num = (int *)number; // Leave for the shop and take some random amount of  time to arrive.
     //printf("student %d leaving for TA shop.\n", num);
     randwait(5);
     printf("\t\t-----student %d arrived at Acad Block.-----\n", num); // Wait for space to open up in the waiting room...
     sem_wait(&waitingRoom);
     printf("\t\t----student %d entering waiting room.----\n", num); // Wait for the TA chair to become free.
     sem_wait(&taChair); // The chair is free so give up your spot in the  waiting room.
     sem_post(&waitingRoom); // Wake up the TA...
     printf("\t\t---student %d waking the TA.---\n", num);
     sem_post(&taPillow); // Wait for the TA to finish cutting your hair.
     sem_wait(&seatBelt); // Give up the chair.
     sem_post(&taChair);
     printf("\t\t---student %d leaving TA .---\n", num);
}

void *TA(void *junk)
{
// While there are still customers to be serviced... Our TA is omnicient and can tell if there are  customers still on the way to his shop.
  
  while (!allDone) { // Sleep until someone arrives and wakes you..
    printf("\t\tThe TA is sleeping\n");
    sem_wait(&taPillow); // Skip this stuff at the end...
    if (!allDone)
    { // Take a random amount of time to cut the student's hair.
     printf("\t\t--The TA is clearing doubts--\n");
     randwait(3);
     printf("\t\t--The TA has finished clearing the doubts.--\n"); // Release the student when done cutting...
     sem_post(&seatBelt);
    }
    else {
         printf("\t\t--The TA is going home for the day.---\n");
    }
   }
}
   
void randwait(int secs) {
     int len = 1; // Generate an arbit number...
     sleep(len);
}
