#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  int fd;
  char *file = "./Text";
  mkfifo(file, 0777 | O_CREAT);
  while (true) {
    fd = open(file, O_WRONLY);
    char input[80];
    printf("Enter message : ");
    fflush(stdout);
    scanf("\t%[^\n]c", input);
    write(fd, input, strlen(input) + 1);
    close(fd);

    fd = open("./Text", O_RDONLY);
    char output[80];
    read(fd, output, sizeof(output));
    printf("got back : %s \n", output);
    close(fd);
  }
}
