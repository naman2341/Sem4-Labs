#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t p1;
    p1 = fork();
    if (p1 > 0)
    {
        //parent proc
        wait(NULL); //wait for child proc to exit(0)
    }
    if(p1 == 0)
    {
        execl("/bin/ls", "./", "-l", NULL);
        exit(0);
    }
}

