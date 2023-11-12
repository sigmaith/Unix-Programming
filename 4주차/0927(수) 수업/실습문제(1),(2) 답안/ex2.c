#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int rfd, wfd, n;
    char buf[256];
    char fname[256];
 
    if(argc != 3) {
        printf("Usage: prog dir file\n");
        exit(1);
    }

    mkdir(argv[1], 0755);//디렉토리 생성

    rfd = open(argv[2], O_RDONLY);//읽기만 가능하게 file open
    if(rfd == -1) {
        perror("Open ");
        exit(1);
    }

    /*파일경로를 넣어서 쓰기용 fd 열기*/
    strcpy(fname, argv[1]);
    strcat(fname, "/");
    strcat(fname, argv[2]);
    wfd = open(fname, O_CREAT | O_WRONLY | O_TRUNC, 0644);//쓰기로 파일오픈
    if(wfd == -1) {
        perror("Create ");
        exit(1);
    }

    while((n = read(rfd, buf, 5)) > 0)
        if(write(wfd, buf, n) != n) perror("Write");

    if(n == -1) perror("Read");
    
    close(rfd);
    close(wfd);
    remove(argv[2]);
}

