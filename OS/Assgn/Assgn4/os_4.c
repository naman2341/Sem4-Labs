// c program to display the files greater than a certain size
// input - directory and minimum file size

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h> //contains constructs that facilitate getting information about files
int main()
{
    DIR *dir;
    struct dirent *dirent;
    struct stat statbuf;
    char path[100];
    int size;
    printf("Enter path: ");
    scanf("%s", path);
    printf("Enter size in kb: ");
    scanf("%d", &size);
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Error in opening the directory\n");
        return 1;
    }
    while ((dirent = readdir(dir)) != NULL)
    {
        if (stat(dirent->d_name, &statbuf) == -1)
        {
            printf("Error in stat\n");
            return 1;
        }
        if (statbuf.st_size / 1024 >= size)
            printf("%s\n", dirent->d_name);
    }
    closedir(dir);
    return 0;
}