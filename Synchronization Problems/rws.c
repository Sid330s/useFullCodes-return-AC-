#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
/*
   semaphores --> mutex,wrt;

   When first reader enters  (readercount==1) we will lock for writers
   and last reader should remove (readercount==1) lock for writers

   Multiple readers are allowed to readers
   But Writer solo will only writer

   mutex is required so that multiple readers will not increament or decrement readercount

*/

pthread_t tid;
pthread_t writerthreads[50],readerthreads[50];
int readercount = 0;
sem_t mutex,wrt;
void *reader(void* param)
{
    sem_wait(&mutex);
    readercount++;
    if(readercount==1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("%d readers  inside\n",readercount); // read operation
    usleep(3); // read for 3 ms
    sem_wait(&mutex);
    readercount--;
    if(readercount==0)
    {
        sem_post(&wrt);
    }
    sem_post(&mutex);
    printf("%d Reader is leaving\n",readercount+1);
    return NULL;
}

void *writer(void* param)
{
    printf("Writer is tring to enter\n");
    sem_wait(&wrt);
    printf("Writer has entered\n");
    sem_post(&wrt);
    printf("Writer is leaving\n");
    return NULL;
}

int main()
{
    int n2,i;
    printf("Enter the number of readers and writers:");
    scanf("%d",&n2);
    printf("\n");
    int n1[n2];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&writerthreads[i],NULL,reader,NULL);
        pthread_create(&readerthreads[i],NULL,writer,NULL);
        //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
    }
    for(i=0;i<n2;i++)
    {
        pthread_join(writerthreads[i],NULL);
        pthread_join(readerthreads[i],NULL);
    }

}
