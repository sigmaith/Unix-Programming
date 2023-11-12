#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int rfd, wfd, n;
    char buf[256];
 
    if(argc != 3) {
        printf("Usage: newcp src target\n");
        exit(1);
    }
    rfd = open(argv[1], O_RDONLY); 
    //읽기 위해 파일 열기
    if(rfd == -1) {
        perror("Open ");
        exit(1);
    }
    wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    //파일 생성, 쓰기, 초기화
    if(wfd == -1) {
        perror("Create ");
        exit(1);
    }

    //읽은 바이트 수가 0일때까지
    while((n = read(rfd, buf, 5)) > 0)
        if(write(wfd, buf, n) != n) perror("Write");
        //쓰기

    if(n == -1) perror("Read");
    
    //파일 디스크립터 닫기
    close(rfd);
    close(wfd);
}

