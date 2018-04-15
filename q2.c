#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5; //number of cats
#define M 3; //number of mouse
sem_t cat[5];
sem_t mice[3];
pthread_mutex_t mutexcat;
pthread_mutex_t mutexmice;// 0 means initial value
int func1(int x);
int func2(int x);

int main()
{
int i;
for(i=0;i<5;i++)
{
sem_init(&cat[i],1,1);
}
for(i=0;i<3;i++)
{
sem_init(&mice[i],1,1);
}
pthread_t t1[5],t2[3];
for(i=0;i<5;i++)
{
pthread_create(&t1[i],NULL,func1,i);
}
for(i=0;i<3;i++)
{
pthread_create(&t2[i],NULL,func2,i);
}
for(i=0;i<5;i++)
{
pthread_join(t1[i],NULL);
}
for(i=0;i<3;i++)
{
pthread_join(t2[i],NULL);
}
}

int func1(int x) // cat
{
sem_wait(&cat[x]);
printf("CAT %d\n",x);
pthread_mutex_lock(&mutexmice);
while(&mutexmice!=1); // try to context switch.
sem_wait(&mice[x]);
printf("CAT IS EATING\n");
sem_post(&cat[x]);
printf("CAT is not hungry\n");
sem_post(&mice[x]);
pthread_mutex_unlock(&mutexmice);
}

int func2(int x)
{
sem_wait(&mice[x]);
printf("MICE %d\n ",x);
pthread_mutex_lock(&mutexcat);
while(&mutexcat!=1);
sem_wait(&cat[x]);
printf("MICE IS EATING\n");
sem_post(&mice[x]);
printf("MICE is not eating\n");
sem_post(&cat[x]);
pthread_mutex_unlock(&mutexcat);
}
