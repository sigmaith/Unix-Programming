#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

/*

명령행 인자로 받은 파일의 심벌릭 링크를 생성하고 
심볼릭 링크 파일의 내용과 원본 파일의 경로를 츨력하는 
프로그램을 작성하시오.

*/
int main(int argc, char* argv[]){
    int n;
    char buf[BUFSIZ] = {0};
    char symname[100] = {0};
    struct stat statbuf;

    n=0;
    while(argv[1][n]!='.'){
        buf[n] = argv[1][n];
        n++;
    }
    buf[n] = '\0';//이름 따오기

    printf("buf: %s\n", buf);
    sprintf(symname, "%s.sym", buf); //문자열 생성하고 출력
    printf("symname: %s\n", symname);
    symlink(argv[1], symname);//심벌릭 링크 생성

    n = readlink(symname, buf, BUFSIZ);
    if(n==-1){
        perror("readlink");
        exit(1);
    }
    buf[n]='\0';
    printf("%s : READLINK = %s\n", symname, buf);//심벌릭 링크의 내용 출력

    realpath(symname, buf);
    printf("%s : REALPATH = %s\n", symname, buf);//원본파일의 경로 출력

    return 0;
}