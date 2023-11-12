#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pd, pd1, n;
    char inmsg[256];

    pd = open("./myfifo", O_RDONLY);
    pd1 = open("./myfifo1", O_WRONLY);
    if(pd == -1) {
        perror("open");
        exit(1);
    }

    printf("Client =====\n");

    while(1) {
        n=read(pd, inmsg, 255);
        printf("Server : %s\n", inmsg);
        printf("Client : ");
        fgets(inmsg, sizeof(inmsg)-1, stdin);
        write(pd1, inmsg, strlen(inmsg)+1);
    }
}

