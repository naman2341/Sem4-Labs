// program to demonstrate fork() 

#include <stdio.h>
#include <unistd.h>

/*
The pid_t data type represents process IDs. You can get the process ID of 
a process by calling getpid. The function getppid returns the process ID 
of the parent of the current process (this is also known as the parent 
process ID). Your program should include the header files `unistd.h' 
 to use these functions.

Data Type: pid_t
The pid_t data type is a signed integer type which is capable of 
representing a process ID. In the GNU library, this is an int.

Function: pid_t getpid (void)
The getpid function returns the process ID of the current process.

Function: pid_t getppid (void)
The getppid function returns the process ID of the parent of the current process.

*/

int main()
{
    pid_t p1;

    int y = 0;

    p1 = fork();

    if (p1 > 0) //parent process
    {
        y = y - 1;

        printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
    }
    else if (p1 == 0) // child process 
    {
        y = y + 1;

        printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);
    }
    else //fork failed
    {
        printf("fork creation failed!!!\n");
    }
}
