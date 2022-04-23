//Qn 1
//Implement pipe operator in C with the following functionality:
//The Parent process reads in a file 'input.txt' and redirects the output of the pipe
//The child process must read the contents of the file and perform a word count

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main()
{
    FILE *fp;
    fp=fopen("input.txt","r");
    char ch;
    int fd[2];
    pipe(fd);
    pid_t pid;
    pid=fork();
    if(pid!=0)
    {
        close(fd[0]); //for read
        while((ch=fgetc(fp))!=EOF)
        {
            write(fd[1],&ch,1);
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]); //for write
        int count=0;
        while(read(fd[0],&ch,1)!=0)
        {
            if(ch==' '||ch=='\n')
            {
                count++;
            }
        }
        count++;
        printf("%d \n\n",count);
        close(fd[0]);
    }
    return 0;
}