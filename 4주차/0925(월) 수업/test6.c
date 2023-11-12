#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;
    mode_t mode;

    //O_READONLY 같은 인자도 사실은 뒤에 붙여줘야 함..
    //fd = open("test.txt", O_CREAT, 0644);
    //fd = open("test.txt", O_CREAT|O_EXCL, 0644);
    //fd = open("test.txt", O_CREAT|O_TRUNC, 0644);
    fd = open("test.txt", O_CREAT|O_RDWR, 0644);
    if (fd == -1) {
        perror("Creat");
        exit(1);
    }
    close(fd);
    return 0;
}

