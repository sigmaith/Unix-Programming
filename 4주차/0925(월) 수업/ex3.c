#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


/*
현재 디렉토리에 어떤 파일의 하드 링크가 여러 개 있을 때 
그 중에 한 파일만 남기고 링크를 모두 끊는 프로그램을 작성하시오

*/
int main(int argc, char* argv[]){
    DIR *dp;
    struct dirent *dent;
    struct stat statbuf;
    int count, n, k, find;
    int ind[256], cind;

    if((dp = opendir(".")) == NULL){
        perror("opendir");
        exit(1);
    }

    while(dent = readdir(dp)){
        stat(dent->d_name, &statbuf);
        if(((statbuf.st_mode & S_IFMT) == S_IFREG) &&(statbuf.st_nlink > 1)){
            /*열린 파일이 regular file이고 링크 개수가 여러개 이면n*/
            unlink(dent->d_name);
            
        }
    }
    closedir(dp);
}