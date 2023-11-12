#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t pid;
    char buf[257];
    int len, status;

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
            close(fd[0]);
            buf[0] = '\0';
            write(fd[1], "Message From Child Process\n", 27);
            close(fd[1]);
            break;
        default :
            close(fd[1]);
            write(1, "Parent Process:", 15);
            len = read(fd[0], buf, 256);
            write(1, buf, len);
            close(fd[0]);
            waitpid(pid, &status, 0);
            break;
    }
}
