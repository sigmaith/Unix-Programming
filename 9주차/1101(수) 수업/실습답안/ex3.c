#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[2], fd2, n;
    pid_t pid;
    char buf[256];

    if(argc != 2) {
        printf("Usage: ex3 filename\n");
        exit(1);
    }
    if(pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            write(fd[1], argv[1], strlen(argv[1])); 
            exit(1); 
            break;
        default :
            while((n=read(fd[0], buf, 256)) <= 0);
            buf[n] = '\0';
            execlp("man", "man", buf, (char *)NULL);
            break;
    }
}

