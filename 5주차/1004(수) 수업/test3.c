#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd, flags;

    fd = open("test.txt", O_RDWR);
    /*fd = open("test.txt", O_RDONLY); 불가능*/
    /*fd = open("test.txt", O_WRONLY); 가능*/
    if (fd == -1) {
        perror("open error (fcntl)");
        exit(1);
    }

    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        perror("fcntl");
        exit(1);
    }

    flags |= O_APPEND;

    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        exit(1);
    }

    if (write(fd, "UNIX Programming Class", 32) != 32) perror("write");
    close(fd);

    return 0;
}


