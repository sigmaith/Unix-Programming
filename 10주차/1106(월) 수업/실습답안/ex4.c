#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid;
    char msg[256], inmsg[256];
    int n, len, status;

    if(pipe(fd1) == -1) {
        perror("pipe");
        exit(1);
    }
    if(pipe(fd2) == -1) {
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            close(fd1[1]);
            close(fd2[0]);

            while(1) {
                n=read(fd1[0], inmsg, 255);
                printf("From Server : %s\n", inmsg);
                printf("Client : ");
                fgets(inmsg, sizeof(inmsg)-1, stdin);
                write(fd2[1], inmsg, strlen(inmsg)+1);
            }
            break;
        default :
            close(fd1[0]);
            close(fd2[1]);
            while(1) {
                printf("Server : ");
                fgets(msg, sizeof(msg)-1, stdin);
                n = write(fd1[1], msg, strlen(msg)+1);
                if(n == -1) {
                    perror("write");
                    exit(1);
                }
                n = read(fd2[0], msg, 255);
                printf("From Client : %s\n", msg);
            }

            break;
    }
}

