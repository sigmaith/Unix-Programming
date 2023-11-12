#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd, n; 
    off_t start, cur;
    char buf[256];
 
    fd = open("test.dat", O_RDONLY);
    if(fd == -1) {
        perror("Open test.dat");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);

    while((n = read(fd, buf, 1)) > 0) {
        write(1, buf, 1);//표준출력-모니터
        start = lseek(fd, 1, SEEK_CUR);
    }

    close(fd);
}

