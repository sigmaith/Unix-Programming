#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

/*

현재 디렉토리에서 inode가 같은 파일을 검색해 
inode을 출력하는 프로그램을 작성하시오

*/

int main(int argc, char* argv[]){
    DIR *dp;
    struct dirent *dent;
    struct stat statbuf;
    int count, n, k, find;
    int ind[256], cind;
    
    if((dp = opendir("."))==NULL){//디렉토리 열기 실패
        perror("opendir");
        exit(1);
    } 

    count = 0;
    while(dent = readdir(dp)){
        stat(dent->d_name, &statbuf);
        ind[count] = (int)statbuf.st_ino; //octal num->decimal로 변환해서 저장
        count++;
    }
    closedir(dp);

    find = 0;
    for(n=0; n<count; n++){
        cind = ind[n];
        for(k=0; k<count; k++){
            if (k!=n && (cind == ind[k]) && (ind[k]!=-1)){
                printf("Same inode: %d\n", cind);
                ind[k] = -1;
                find = 1;
            }
        }
    }
    if(!find) printf("No same inode file\n");

    stat(argv[1], &statbuf);
    inode = (int)statbuf.st_uid;
    
    return 0;
}

