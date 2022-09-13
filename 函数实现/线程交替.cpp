#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <wait.h>
using namespace std;

sem_t s1;
sem_t s2;
sem_t s3;

void* print1(void *arg)
{
    while(1)
    {
        sem_wait(&s3);
        cout<<1<<" ";
        cout.flush();
        sleep(1);
        sem_post(&s1);
    }
}

void* print2(void *arg)
{
    while(1)
    {
        sem_wait(&s1);
        cout<<2<<" ";
        cout.flush();
        sleep(1);
        sem_post(&s2);
    }
}

void* print3(void *arg)
{
    while(1)
    {
        sem_wait(&s2);
        cout<<3<<" ";
        cout.flush();
        sleep(1);
        sem_post(&s3);
    }
}

int main()
{
    pthread_t pid1,pid2,pid3;
    sem_init(&s1,0,0);
    sem_init(&s2,0,0);
    sem_init(&s3,0,1);
    pthread_create(&pid1,NULL,print1,NULL);
    pthread_create(&pid2,NULL,print2,NULL);
    pthread_create(&pid3,NULL,print3,NULL);

    pthread_join(pid1,NULL);
    
    
    return 0;
}