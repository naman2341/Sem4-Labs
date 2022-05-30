// Write a program to truncate files in a directory created after certain date
#include <stdio.h>
#include <dirent.h>    //FACILITATES DIRECTORY TRAVERSING
#include <sys/types.h> //CONTAINS TYPEDEF STRUCTURES AND SYMBOLS
#include <sys/stat.h>
#include <unistd.h> //provides access to posix os APU
#include <fcntl.h>  //allows a program to place a write or read lock
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    DIR *dir; // file descriptor
    struct dirent *dirent;
    struct stat statbuf; // stores information on files
    int fd;
    char *filename;
    int size;
    int half;
    char date[100];
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s", date);
    char path[100];

    printf("Enter the path of the directory: ");
    scanf("%s", path);
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Cannot open directory\n");
        return 1;
    }
    while ((dirent = readdir(dir)) != NULL)
    {
        filename = dirent->d_name;
        if (stat(filename, &statbuf) == -1)
        {
            printf("Cannot stat file %s\n", filename);
            continue;
        }
        if (S_ISREG(statbuf.st_mode)) // S_ISREG interprets values in stat-struct as returned from stat
        {
            fd = open(filename, O_RDWR); // open for reading and writing
            if (fd == -1)
            {
                printf("Cannot open file %s\n", filename);
                continue;
            }
            size = statbuf.st_size;
            half = size / 2;
            if (ftruncate(fd, half) == -1)
            {
                printf("Cannot truncate file %s\n", filename);
                continue;
            }
            if (strcmp(date, ctime(&statbuf.st_ctime)) < 0) // calender time
            {
                printf("File %s truncated to %d bytes\n", filename, half);
            }
        }
    }
    closedir(dir);
    return 0;
}