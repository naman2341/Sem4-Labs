// This is a 2 pipe, only rcv from one side and send from both sides
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  mkfifo("./Text", 0777 | O_CREAT);
  // creating named pipe
  int fd;
  while (true) {
    fd = open("./Text", O_RDONLY);
    char output[80];
    read(fd, output, sizeof(output));
    printf("got back : %s \n", output);
    close(fd);

    fd = open("./Text", O_WRONLY);
    char input[80];
    printf("Enter message : ");
    fflush(stdout);
    scanf("\t%[^\n]c", input);
    write(fd, input, 80);
    close(fd);
  }
}
