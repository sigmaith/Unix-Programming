#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[256];
    char symname[1024];
    int n;

    if (argc == 1) { //파일을 인자로 쓰지 않았을 경우
        printf("Usage: mysym filename\n");
        exit(1);
    }

    n = 0;
    while(argv[1][n] != '.') {
        buf[n] = argv[1][n];
        n++;
    }
    buf[n] = '\0';//buf에 파일명 받기

    printf("buf: %s\n", buf);
    sprintf(symname, "%s.sym", buf);//symname 문자열 생성
    printf("symname: %s\n", symname);

    symlink(argv[1], symname);//심벌릭 링크 생성

    n = readlink(symname, buf, sizeof(buf));
    if (n == -1) {
        perror("readlink");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s: READLINK = %s\n", symname,  buf);//심벌링 링크파일 읽기

    realpath(symname, buf);//buf에 symname 파일 경로 받기
    printf("%s: REALPATH = %s\n", symname,  buf);//경로출력
}

