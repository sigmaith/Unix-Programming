#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pd, fd, n;
    char msg[256];

    printf("Server =====\n");
    
    unlink("./MY-FIFO");
    if(mkfifo("./MY-FIFO", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    if((pd = open("./MY-FIFO", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    if((fd = open("./ex5_data.txt", O_CREAT|O_WRONLY, 0644)) == -1) {
        perror("open");
        exit(1);
    }

    while((n=read(pd, msg, 256)) > 0) {
        write(1, msg, n);
        write(fd, msg, n);
    }

    close(fd);
    close(pd);
}

