//Program to demo threads

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

//Create a global variable which will be changed in the threads
int g=0;

//The function to be executed by all threads
void *myThreadFucntion(void *varg)
{
    int i=0;
    while(i<10)
    {
        printf("\nThread %d: g=%d",(int)varg,g);
        g++;
        sleep(1);
        i++;
    }

    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t tid;
    for(i=0;i<5;i++)
    {
        pthread_create(&tid,NULL,myThreadFucntion,(void *)i);
    }
    printf("\nMain thread: g=%d",g);
    return 0;

}
