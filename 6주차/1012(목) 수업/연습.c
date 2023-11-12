#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main(){
    
    int fd;
    int nread;
    pid_t pid;
    char buf[10];

    if((fd=open("testdata", O_RDONLY)) ==-1)
        perror("open failed");

    read(fd, buf, 10);

    printpos("Before fork", fd);

    switch(pid = fork()){
        case -1:
            perror("fork failed");
            break;
        case 0:
            printpos("Child before read", fd);
            read(fd, buf, 10);
            printpos("Child after read", fd);
            close(fd);
            break;
    }

}