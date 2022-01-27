// program to demonstrate creation of child processes and 
//executing commands using fork(), execl() and wait() 

/*
C System Functions in Exec Family:
The exec function families are defined in the header unistd.h. 
So, you must use this header on the 
C program where you want to use these functions.

execl() System Function:
In execl() system function takes the path of the 
executable binary file (i.e. /bin/ls) as the first 
and second argument. Then, the arguments (i.e. -lh, /home) that 
you want to pass to the executable followed by NULL. 
Then execl() system function runs the command and prints the output.
 If any error occurs, then execl() returns -1. Otherwise, it returns nothing.

Syntax:
int execl(const char *path, const char *arg, ..., NULL);
An example of the execl() system function is given below:

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2;

    int y = 0;

    p1 = fork();

    if (p1 > 0) //parent process
    {
        wait(NULL);

        y = y - 1;

        printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);

        execl("/bin/ls", "/home/nivedita/osprograms", NULL);
    }
    else if (p1 == 0) // child process 
    {
        p2 = fork();

        if (p2 > 0)
        {
           wait(NULL);
        }
        else if (p2 == 0)
        {
           y = y + 5;
           
           printf("This is grandchild. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);

           execl("/bin/ls", "/home/nivedita/osprograms", "-r", NULL);

           exit(0);
        }

        y = y + 1;

        printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);

        char *a[] = {NULL};

        execv("/home/nivedita/osprograms/example1.exe", a);

        exit(0);
    }
    else //fork failed
    {
        printf("fork creation failed!!!\n");
    }
}
