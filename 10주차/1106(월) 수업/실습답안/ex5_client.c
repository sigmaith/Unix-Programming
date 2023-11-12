#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pd, fd, n;
    char msg[256];

    if(argc != 2) {
        printf("Usage: ex10_13c.out filename\n");
        exit(1);
    }

    if((pd = open("./MY-FIFO", O_WRONLY)) == -1) {
        perror("open");
        exit(1);
    }

    if((fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    while((n=read(fd, msg, 256)) > 0)
        write(pd, msg, n);

    close(fd);
    close(pd);
}

