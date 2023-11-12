#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pd, pd1, n;
    char msg[256];

    if(mkfifo("./myfifo", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    if(mkfifo("./myfifo1", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    pd = open("./myfifo", O_WRONLY);
    pd1 = open("./myfifo1", O_RDONLY);
    if(pd == -1) {
        perror("open");
        exit(1);
    }

    while(1) {
        printf("Server : ");
        fgets(msg, sizeof(msg)-1, stdin);
        n = write(pd, msg, strlen(msg)+1);
        if(n == -1) {
            perror("write");
            exit(1);
        }
        n = read(pd1, msg, 255);
        printf("Client : %s\n", msg);
    }
}

