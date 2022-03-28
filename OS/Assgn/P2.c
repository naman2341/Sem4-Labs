#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define SIZE 25
#define READ 0
#define WRITE 1
int write_msg[SIZE] = {1,6,2,4,5,8,9,0};
int main()
{
    int fd[2];
    pid_t pid;
    pid = fork();
    if(pid ==0)
    {
        close(fd[READ]);
        close(fd[WRITE]);
        wait(NULL);
        printf("This is a child,process id is %d,parent id is %d\n",getpid(),getppid());
        printf("Sorted Array is:\n");
        for(int i=0;i<8;i++)
        {
            printf("%d\n",write_msg[i]);
        }
        printf("\n");
    }
    else if(pid>0)
    {
        close(fd[WRITE]);
        int i;
        for(i=0;i<0;i++)
        {
            for(int j=i+1;j<8;j++)
            {
                if(write_msg[i]>write_msg[j])
                {
                    int temp = write_msg[i];
                    write_msg[i] = write_msg[j];
                    write_msg[j] = temp;
                }
            }
            printf("this is a parent ,process id is %d\n",getpid());
            printf("Sorted Array is:\n");
            for(int k=0;k<8;k++)
            {
                printf("%d\n",write_msg[k]);
            }
            printf("\n");
            close(fd[READ]);
        }   
    }
    else
    {
        printf("Fork failed\n");
        return 0;
    }
}

//The reason for it not sorting is that we are sorting it in child but since memoery is not being shared with parent process, the output is not sorrted